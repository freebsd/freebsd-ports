--- src/3rdparty/chromium/ipc/ipc_channel_common.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel_common.cc
@@ -11,7 +11,7 @@ namespace IPC {
 
 namespace IPC {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 namespace {
 int g_global_pid = 0;
