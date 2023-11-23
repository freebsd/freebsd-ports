--- src/3rdparty/chromium/third_party/perfetto/src/base/unix_socket.cc.orig	2022-10-24 13:33:33 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/base/unix_socket.cc
@@ -42,7 +42,7 @@
 #include <unistd.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || defined(__FreeBSD__)
 #include <sys/ucred.h>
 #endif
 
@@ -803,9 +803,13 @@ void UnixSocket::ReadPeerCredentialsPosix() {
     return;
   PERFETTO_CHECK(peer_cred_mode_ != SockPeerCredMode::kIgnore);
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if !defined(__FreeBSD__) && PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+  struct sockpeercred user_cred;
+#else
   struct ucred user_cred;
+#endif
   socklen_t len = sizeof(user_cred);
   int fd = sock_raw_.fd();
   int res = getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &user_cred, &len);
