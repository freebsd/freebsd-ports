--- chrome/browser/extensions/api/messaging/launch_context_posix.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/extensions/api/messaging/launch_context_posix.cc
@@ -85,7 +85,7 @@ std::optional<LaunchContext::ProcessState> LaunchConte
 
   options.current_directory = command_line.GetProgram().DirName();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Don't use no_new_privs mode, e.g. in case the host needs to use sudo.
   options.allow_new_privs = true;
 #endif
