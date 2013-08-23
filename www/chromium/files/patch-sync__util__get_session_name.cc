--- sync/util/get_session_name.cc.orig	2013-08-16 23:59:39.000000000 +0300
+++ sync/util/get_session_name.cc	2013-08-17 00:00:27.000000000 +0300
@@ -14,7 +14,7 @@
 #if defined(OS_CHROMEOS)
 #include "base/command_line.h"
 #include "chromeos/chromeos_switches.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "sync/util/get_session_name_linux.h"
 #elif defined(OS_IOS)
 #include "sync/util/get_session_name_ios.h"
@@ -59,7 +59,7 @@
   // like "stumpy-signed-mp-v2keys" etc. The information can be checked on
   // "CHROMEOS_RELEASE_BOARD" line in chrome://system.
   session_name = board.substr(0, 6) == "stumpy" ? "Chromebox" : "Chromebook";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   session_name = internal::GetHostname();
 #elif defined(OS_IOS)
   session_name = internal::GetComputerName();
