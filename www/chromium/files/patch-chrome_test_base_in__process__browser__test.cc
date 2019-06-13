--- chrome/test/base/in_process_browser_test.cc.orig	2019-06-04 18:55:19 UTC
+++ chrome/test/base/in_process_browser_test.cc
@@ -74,6 +74,10 @@
 #include "chrome/test/base/scoped_bundle_swizzler_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 #if defined(OS_WIN)
 #include "base/win/scoped_com_initializer.h"
 #include "base/win/windows_version.h"
@@ -106,7 +110,7 @@
 #include "ui/events/test/event_generator.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/views/test/test_desktop_screen_x11.h"
 #endif
 
