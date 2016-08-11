--- sync/util/get_session_name.cc.orig	2016-03-25 13:04:51 UTC
+++ sync/util/get_session_name.cc
@@ -15,7 +15,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "chromeos/system/devicetype.h"
-#elif defined(OS_LINUX)
+#elif (defined(OS_LINUX) || defined(OS_BSD))
 #include "sync/util/get_session_name_linux.h"
 #elif defined(OS_IOS)
 #include "sync/util/get_session_name_ios.h"
@@ -51,7 +51,7 @@ std::string GetSessionNameSynchronously(
       session_name = "Chromebook";
       break;
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   session_name = internal::GetHostname();
 #elif defined(OS_IOS)
   session_name = internal::GetComputerName();
