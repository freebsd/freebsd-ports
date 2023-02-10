--- src/3rdparty/chromium/net/socket/socket_posix.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/socket/socket_posix.cc
@@ -519,7 +519,7 @@ int SocketPosix::DoWrite(IOBuffer* buf, int buf_len) {
 }
 
 int SocketPosix::DoWrite(IOBuffer* buf, int buf_len) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Disable SIGPIPE for this write. Although Chromium globally disables
   // SIGPIPE, the net stack may be used in other consumers which do not do
   // this. MSG_NOSIGNAL is a Linux-only API. On OS X, this is a setsockopt on
