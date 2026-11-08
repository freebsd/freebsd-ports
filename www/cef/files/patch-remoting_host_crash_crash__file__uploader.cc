--- remoting/host/crash/crash_file_uploader.cc.orig	2025-10-30 15:44:36 UTC
+++ remoting/host/crash/crash_file_uploader.cc
@@ -45,7 +45,7 @@ constexpr char kMinidumpFileName[] = "dump";
 
 #if BUILDFLAG(IS_WIN)
 constexpr char kProductNameValue[] = "Chromoting";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductNameValue[] = "Chromoting_Linux";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kProductNameValue[] = "Chromoting_Mac";
