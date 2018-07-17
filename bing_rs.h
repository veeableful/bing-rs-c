#pragma once

typedef struct BingSpeech BingSpeech;
typedef struct BingSpeechWebsocket BingSpeechWebsocket;

typedef struct BingSpeechWebsocketHandler {
    void *on_turn_start;
    void *on_turn_end;
    void *on_speech_start_detected;
    void *on_speech_end_detected;
    void *on_speech_hypothesis;
    void *on_speech_phrase;
} BingSpeechWebsocketHandler;

typedef struct BingSpeechResult {
    double confidence;
    char *lexical;
    char *itn;
    char *masked_itn;
    char *display;
} BingSpeechResult;

typedef struct BingSpeechPhrase {
    char *recognition_status;
    char *display_text;
    double offset;
    double duration;
    BingSpeechResult *nbest;
    int nbest_count;
} BingSpeechPhrase;

typedef struct BingSpeechHypothesis {
    char *text;
    double offset;
    double duration;
} BingSpeechHypothesis;

extern BingSpeech * bing_speech_new(const char *subscription_key);
extern void bing_speech_free(BingSpeech *);
extern char * bing_speech_fetch_token(BingSpeech *);

extern BingSpeechWebsocket * bing_speech_websocket(BingSpeech *, BingSpeechWebsocketHandler);
extern int bing_speech_websocket_audio(BingSpeechWebsocket *, const char *audio, int audio_size);
extern int bing_speech_websocket_close(BingSpeechWebsocket *);