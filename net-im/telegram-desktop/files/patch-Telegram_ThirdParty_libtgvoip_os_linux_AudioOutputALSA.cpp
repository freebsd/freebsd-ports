--- Telegram/ThirdParty/libtgvoip/os/linux/AudioOutputALSA.cpp.orig	2018-11-23 01:03:16 UTC
+++ Telegram/ThirdParty/libtgvoip/os/linux/AudioOutputALSA.cpp
@@ -11,6 +11,10 @@
 #include "../../logging.h"
 #include "../../VoIPController.h"
 
+#ifndef typeof
+#define typeof __typeof__
+#endif
+
 #define BUFFER_SIZE 960
 #define CHECK_ERROR(res, msg) if(res<0){LOGE(msg ": %s", _snd_strerror(res)); failed=true; return;}
 #define CHECK_DL_ERROR(res, msg) if(!res){LOGE(msg ": %s", dlerror()); failed=true; return;}
