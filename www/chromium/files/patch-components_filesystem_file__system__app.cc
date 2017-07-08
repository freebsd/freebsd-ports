--- components/filesystem/file_system_app.cc.orig	2017-06-05 19:03:05 UTC
+++ components/filesystem/file_system_app.cc
@@ -22,7 +22,7 @@
 #elif defined(OS_ANDROID)
 #include "base/base_paths_android.h"
 #include "base/path_service.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MACOSX)
@@ -78,7 +78,7 @@ base::FilePath FileSystemApp::GetUserDataDir() {
     CHECK(PathService::Get(base::DIR_APP_DATA, &path));
 #elif defined(OS_ANDROID)
     CHECK(PathService::Get(base::DIR_ANDROID_APP_DATA, &path));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     std::unique_ptr<base::Environment> env(base::Environment::Create());
     path = base::nix::GetXDGDirectory(env.get(),
                                       base::nix::kXdgConfigHomeEnvVar,
