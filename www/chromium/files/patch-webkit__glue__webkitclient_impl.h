--- webkit/glue/webkitclient_impl.h.orig	2011-02-03 10:01:07.000000000 +0100
+++ webkit/glue/webkitclient_impl.h	2011-02-05 00:08:55.000000000 +0100
@@ -10,7 +10,7 @@
 #include "third_party/WebKit/Source/WebKit/chromium/public/WebKitClient.h"
 #if defined(OS_WIN)
 #include "webkit/glue/webthemeengine_impl_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
 #include "webkit/glue/webthemeengine_impl_linux.h"
 #elif defined(OS_MACOSX)
 #include "webkit/glue/webthemeengine_impl_mac.h"
@@ -88,7 +88,7 @@
   double shared_timer_fire_time_;
   int shared_timer_suspended_;  // counter
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_POSIX)
   WebThemeEngineImpl theme_engine_;
 #endif
 };
