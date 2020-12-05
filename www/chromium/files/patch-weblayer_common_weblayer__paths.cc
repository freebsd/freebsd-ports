--- weblayer/common/weblayer_paths.cc.orig	2020-11-13 06:37:06 UTC
+++ weblayer/common/weblayer_paths.cc
@@ -17,7 +17,7 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -35,7 +35,7 @@ bool GetDefaultUserDataDirectory(base::FilePath* resul
     return false;
   *result = result->AppendASCII("weblayer");
   return true;
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   base::FilePath config_dir(base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir));
