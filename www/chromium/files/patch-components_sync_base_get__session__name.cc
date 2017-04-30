--- components/sync/base/get_session_name.cc.orig	2017-04-19 19:06:33 UTC
+++ components/sync/base/get_session_name.cc
@@ -15,7 +15,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "chromeos/system/devicetype.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "components/sync/base/get_session_name_linux.h"
 #elif defined(OS_IOS)
 #include "components/sync/base/get_session_name_ios.h"
@@ -51,7 +51,7 @@ std::string GetSessionNameSynchronously(
       session_name = "Chromebook";
       break;
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   session_name = internal::GetHostname();
 #elif defined(OS_IOS)
   session_name = internal::GetComputerName();
