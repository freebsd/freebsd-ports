--- Telegram/ThirdParty/libtgvoip/os/linux/AudioInputALSA.cpp.orig	2018-11-23 01:03:16 UTC
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
