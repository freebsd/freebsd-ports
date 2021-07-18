--- extensions/shell/app/shell_main_delegate.cc.orig	2021-04-14 18:41:04 UTC
+++ extensions/shell/app/shell_main_delegate.cc
@@ -39,7 +39,7 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MAC)
 #include "base/base_paths_mac.h"
@@ -75,7 +75,7 @@ base::FilePath GetDataPath() {
     return cmd_line->GetSwitchValuePath(switches::kContentShellDataPath);
 
   base::FilePath data_dir;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   data_dir = base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir);
