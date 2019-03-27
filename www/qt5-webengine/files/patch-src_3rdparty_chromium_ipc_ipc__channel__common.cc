--- src/3rdparty/chromium/ipc/ipc_channel_common.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel_common.cc
@@ -9,7 +9,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
