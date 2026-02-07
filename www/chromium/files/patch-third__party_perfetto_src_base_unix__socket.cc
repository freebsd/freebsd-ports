--- third_party/perfetto/src/base/unix_socket.cc.orig	2026-01-14 10:56:38 UTC
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -1067,9 +1067,15 @@ void UnixSocket::ReadPeerCredentialsPosix() {
   int res = getpeereid(fd, &peer_uid_, nullptr);
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
