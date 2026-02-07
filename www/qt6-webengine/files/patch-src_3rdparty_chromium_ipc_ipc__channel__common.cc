--- src/3rdparty/chromium/ipc/ipc_channel_common.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel_common.cc
@@ -10,7 +10,7 @@ namespace IPC {
 
 namespace IPC {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 namespace {
 int g_global_pid = 0;
