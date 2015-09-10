--- sync/util/get_session_name.cc.orig	2015-08-22 15:01:57.000000000 -0400
+++ sync/util/get_session_name.cc	2015-09-03 11:15:14.369871000 -0400
@@ -14,7 +14,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "chromeos/system/devicetype.h"
-#elif defined(OS_LINUX)
+#elif (defined(OS_LINUX) || defined(OS_BSD))
 #include "sync/util/get_session_name_linux.h"
 #elif defined(OS_IOS)
 #include "sync/util/get_session_name_ios.h"
@@ -50,7 +50,7 @@
       session_name = "Chromebook";
       break;
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   session_name = internal::GetHostname();
 #elif defined(OS_IOS)
   session_name = internal::GetComputerName();
