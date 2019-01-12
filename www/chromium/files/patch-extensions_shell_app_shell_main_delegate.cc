--- extensions/shell/app/shell_main_delegate.cc.orig	2019-01-11 19:10:53.125547000 +0100
+++ extensions/shell/app/shell_main_delegate.cc	2019-01-11 19:11:57.764029000 +0100
@@ -38,7 +38,7 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
@@ -52,7 +52,7 @@
 
 namespace {
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 extensions::ShellCrashReporterClient* GetCrashReporterClient() {
   static base::NoDestructor<extensions::ShellCrashReporterClient> instance;
   return instance.get();
@@ -70,7 +70,7 @@
     return cmd_line->GetSwitchValuePath(switches::kContentShellDataPath);
 
   base::FilePath data_dir;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   data_dir = base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir);
