--- remoting/host/remote_open_url_constants.cc.orig	2021-07-28 08:18:44 UTC
+++ remoting/host/remote_open_url_constants.cc
@@ -11,7 +11,7 @@ namespace remoting {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 // The channel name on Linux is the path to a unix domain socket, so it needs
 // to be an absolute path to allow the IPC client binary to be executed from
