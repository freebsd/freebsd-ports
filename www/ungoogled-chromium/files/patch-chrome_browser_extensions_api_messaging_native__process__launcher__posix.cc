--- chrome/browser/extensions/api/messaging/native_process_launcher_posix.cc.orig	2024-06-22 08:49:42 UTC
+++ chrome/browser/extensions/api/messaging/native_process_launcher_posix.cc
@@ -84,7 +84,7 @@ bool NativeProcessLauncher::LaunchNativeProcess(
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Don't use no_new_privs mode, e.g. in case the host needs to use sudo.
   options.allow_new_privs = true;
 #endif
