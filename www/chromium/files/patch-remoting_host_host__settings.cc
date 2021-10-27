--- remoting/host/host_settings.cc.orig	2021-09-14 01:52:00 UTC
+++ remoting/host/host_settings.cc
@@ -13,9 +13,9 @@
 #include "remoting/host/mac/constants_mac.h"
 #endif  // defined(OS_APPLE)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "remoting/host/linux/file_path_util.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace remoting {
 
@@ -48,7 +48,7 @@ HostSettings* HostSettings::GetInstance() {
 #if defined(OS_APPLE)
   static const base::FilePath settings_file(kHostSettingsFilePath);
   static base::NoDestructor<FileHostSettings> instance(settings_file);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   static base::NoDestructor<FileHostSettings> instance(base::FilePath(
       GetConfigDirectoryPath().Append(GetHostHash() + ".settings.json")));
 #else
