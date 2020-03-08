--- third_party/perfetto/src/base/unix_socket.cc.orig	2020-03-03 18:55:28 UTC
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -593,7 +593,8 @@ void UnixSocket::ReadPeerCredentials() {
     return;
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct ucred user_cred;
   socklen_t len = sizeof(user_cred);
   int fd = sock_raw_.fd();
