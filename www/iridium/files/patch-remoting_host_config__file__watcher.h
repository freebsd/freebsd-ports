--- remoting/host/config_file_watcher.h.orig	2026-06-10 12:51:34 UTC
+++ remoting/host/config_file_watcher.h
@@ -20,7 +20,7 @@ namespace remoting {
 extern const char kHostConfigSwitchName[];
 extern const base::FilePath::CharType kDefaultHostConfigFile[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::FilePath::CharType kDefaultUnprivilegedConfigFileName[];
 #endif
 
