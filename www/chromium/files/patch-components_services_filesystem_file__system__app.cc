--- components/services/filesystem/file_system_app.cc.orig	2019-07-24 18:58:21 UTC
+++ components/services/filesystem/file_system_app.cc
@@ -19,7 +19,7 @@
 #elif defined(OS_ANDROID)
 #include "base/base_paths_android.h"
 #include "base/path_service.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MACOSX)
@@ -68,7 +68,7 @@ base::FilePath FileSystemApp::GetUserDataDir() {
     CHECK(base::PathService::Get(base::DIR_APP_DATA, &path));
 #elif defined(OS_ANDROID)
     CHECK(base::PathService::Get(base::DIR_ANDROID_APP_DATA, &path));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     std::unique_ptr<base::Environment> env(base::Environment::Create());
     path = base::nix::GetXDGDirectory(
         env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir);
