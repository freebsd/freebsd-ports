--- ipc/ipc_channel_common.cc.orig	2017-08-10 04:18:14.155067000 +0200
+++ ipc/ipc_channel_common.cc	2017-08-10 04:18:32.944727000 +0200
@@ -9,7 +9,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
