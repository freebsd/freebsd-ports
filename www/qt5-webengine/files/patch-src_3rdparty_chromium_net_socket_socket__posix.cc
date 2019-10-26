--- src/3rdparty/chromium/net/socket/socket_posix.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/net/socket/socket_posix.cc
@@ -568,7 +568,7 @@ void SocketPosix::ReadCompleted() {
 }
 
 int SocketPosix::DoWrite(IOBuffer* buf, int buf_len) {
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Disable SIGPIPE for this write. Although Chromium globally disables
   // SIGPIPE, the net stack may be used in other consumers which do not do
   // this. MSG_NOSIGNAL is a Linux-only API. On OS X, this is a setsockopt on
