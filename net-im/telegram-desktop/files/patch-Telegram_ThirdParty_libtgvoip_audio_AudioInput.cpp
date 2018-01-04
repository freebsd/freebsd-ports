--- Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp.orig	2017-07-06 17:16:18 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp
@@ -20,7 +20,7 @@
 #include "../os/windows/AudioInputWave.h"
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "../os/linux/AudioInputALSA.h"
 #include "../os/linux/AudioInputPulse.h"
 #else
