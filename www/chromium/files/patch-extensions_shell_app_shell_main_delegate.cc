--- extensions/shell/app/shell_main_delegate.cc.orig	2019-01-09 22:03:40.116892000 +0100
+++ extensions/shell/app/shell_main_delegate.cc	2019-01-09 22:04:39.261286000 +0100
@@ -38,13 +38,13 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "components/crash/content/app/breakpad_linux.h"         // nogncheck
 #include "components/crash/content/app/crash_reporter_client.h"  // nogncheck
 #include "extensions/shell/app/shell_crash_reporter_client.h"
@@ -70,7 +70,7 @@
     return cmd_line->GetSwitchValuePath(switches::kContentShellDataPath);
 
   base::FilePath data_dir;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   data_dir = base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir);
