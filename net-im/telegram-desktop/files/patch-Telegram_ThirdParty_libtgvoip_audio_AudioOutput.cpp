--- Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp.orig	2017-07-06 17:16:18 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp
@@ -21,7 +21,7 @@
 #include "../os/windows/AudioOutputWave.h"
 #endif
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "../os/linux/AudioOutputALSA.h"
 #include "../os/linux/AudioOutputPulse.h"
 #else
