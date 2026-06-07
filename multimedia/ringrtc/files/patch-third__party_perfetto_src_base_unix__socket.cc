--- src/webrtc/src/third_party/perfetto/src/base/unix_socket.cc.orig	2023-09-13 12:11:42 UTC
+++ src/webrtc/src/third_party/perfetto/src/base/unix_socket.cc
@@ -1073,9 +1073,15 @@ void UnixSocket::ReadPeerCredentialsPosix() {
   ignore_result(peer_gid);
   PERFETTO_CHECK(res == 0);
   // There is no pid when obtaining peer credentials for QNX
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#elif (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
+  struct sockpeercred user_cred;
+#else
   struct ucred user_cred;
+#endif
   socklen_t len = sizeof(user_cred);
   int fd = sock_raw_.fd();
   int res = getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &user_cred, &len);
