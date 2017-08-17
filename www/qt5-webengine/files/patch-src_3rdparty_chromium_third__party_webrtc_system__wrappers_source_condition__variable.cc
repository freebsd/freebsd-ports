--- src/3rdparty/chromium/third_party/webrtc/system_wrappers/source/condition_variable.cc.orig	2017-04-19 18:46:43 UTC
+++ src/3rdparty/chromium/third_party/webrtc/system_wrappers/source/condition_variable.cc
@@ -14,7 +14,7 @@
 #include <windows.h>
 #include "webrtc/system_wrappers/source/condition_variable_event_win.h"
 #include "webrtc/system_wrappers/source/condition_variable_native_win.h"
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC) || defined(BSD)
 #include <pthread.h>
 #include "webrtc/system_wrappers/source/condition_variable_posix.h"
 #endif
@@ -31,7 +31,7 @@ ConditionVariableWrapper* ConditionVaria
     ret_val = new ConditionVariableEventWin();
   }
   return ret_val;
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC) || defined(BSD)
   return ConditionVariablePosix::Create();
 #else
   return NULL;
