--- src/3rdparty/chromium/net/socket/socket_posix.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/net/socket/socket_posix.cc
@@ -517,7 +517,7 @@ int SocketPosix::DoWrite(IOBuffer* buf, int buf_len) {
 }
 
 int SocketPosix::DoWrite(IOBuffer* buf, int buf_len) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   // Disable SIGPIPE for this write. Although Chromium globally disables
   // SIGPIPE, the net stack may be used in other consumers which do not do
   // this. MSG_NOSIGNAL is a Linux-only API. On OS X, this is a setsockopt on
