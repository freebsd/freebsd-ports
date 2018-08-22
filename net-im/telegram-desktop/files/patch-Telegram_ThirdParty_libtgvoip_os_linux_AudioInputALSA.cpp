--- Telegram/ThirdParty/libtgvoip/os/linux/AudioInputALSA.cpp.orig	2018-07-17 16:48:21 UTC
+++ Telegram/ThirdParty/libtgvoip/os/linux/AudioInputALSA.cpp
@@ -12,6 +12,10 @@
 #include "../../logging.h"
 #include "../../VoIPController.h"
 
+#ifndef typeof
+#define typeof __typeof__
+#endif
+
 using namespace tgvoip::audio;
 
 #define BUFFER_SIZE 960
@@ -172,4 +176,4 @@ void AudioInputALSA::EnumerateDevices(st
 	}
 
 	dlclose(lib);
-}
\ No newline at end of file
+}
