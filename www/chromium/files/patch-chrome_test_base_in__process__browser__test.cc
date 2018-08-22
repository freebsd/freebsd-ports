--- chrome/test/base/in_process_browser_test.cc.orig	2018-08-08 21:10:43.000000000 +0200
+++ chrome/test/base/in_process_browser_test.cc	2018-08-21 00:58:24.257483000 +0200
@@ -69,6 +69,10 @@
 #include "chrome/test/base/scoped_bundle_swizzler_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 #if defined(OS_WIN)
 #include "base/win/scoped_com_initializer.h"
 #include "base/win/windows_version.h"
@@ -88,7 +92,7 @@
 #include "chrome/test/base/default_ash_event_generator_delegate.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/views/test/test_desktop_screen_x11.h"
 #endif
 
