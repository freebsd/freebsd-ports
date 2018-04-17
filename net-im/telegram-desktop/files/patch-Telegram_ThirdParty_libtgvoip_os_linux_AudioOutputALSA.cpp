--- Telegram/ThirdParty/libtgvoip/os/linux/AudioOutputALSA.cpp.orig	2018-02-07 04:46:53 UTC
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
@@ -180,4 +184,4 @@ void AudioOutputALSA::EnumerateDevices(s
 	}
 
 	dlclose(lib);
-}
\ No newline at end of file
+}
