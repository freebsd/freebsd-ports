--- Telegram/ThirdParty/libtgvoip/os/linux/AudioPulse.cpp.orig	2018-07-17 16:48:21 UTC
+++ Telegram/ThirdParty/libtgvoip/os/linux/AudioPulse.cpp
@@ -7,6 +7,9 @@
 #include "AudioPulse.h"
 #include <dlfcn.h>
 #include "../../logging.h"
+#ifdef __FreeBSD__
+#include <libgen.h>
+#endif
 
 #define DECLARE_DL_FUNCTION(name) typeof(name)* AudioPulse::_import_##name=NULL
 #define CHECK_DL_ERROR(res, msg) if(!res){LOGE(msg ": %s", dlerror()); return false;}
@@ -283,4 +286,4 @@ bool AudioPulse::DoOneOperation(std::fun
 		}
 		pa_mainloop_iterate(ml, 1, NULL);
 	}
-}
\ No newline at end of file
+}
