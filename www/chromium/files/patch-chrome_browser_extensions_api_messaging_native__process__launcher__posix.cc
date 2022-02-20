--- chrome/browser/extensions/api/messaging/native_process_launcher_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/extensions/api/messaging/native_process_launcher_posix.cc
@@ -82,7 +82,7 @@ bool NativeProcessLauncher::LaunchNativeProcess(
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Don't use no_new_privs mode, e.g. in case the host needs to use sudo.
   options.allow_new_privs = true;
 #endif
