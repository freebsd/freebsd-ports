/usr/local/include/AL/alc.h:34:26: error: typedef redefinition with different types ('struct ALCdevice' vs 'struct ALCdevice_struct')
typedef struct ALCdevice ALCdevice;
                         ^
.../uTox/src/av/audio.h:8:33: note: previous definition is here
typedef struct ALCdevice_struct ALCdevice;
                                ^

--- src/av/audio.h.orig	2019-09-21 22:31:59 UTC
+++ src/av/audio.h
@@ -4,8 +4,7 @@
 #include <stdbool.h>
 #include <stdint.h>
 #include <stdbool.h>
-
-typedef struct ALCdevice_struct ALCdevice;
+#include <AL/alc.h>
 
 extern bool utox_audio_thread_init;
 
