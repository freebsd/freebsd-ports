--- third_party/perfetto/src/base/unix_socket.cc.orig	2018-12-15 19:07:57.840463000 +0100
+++ third_party/perfetto/src/base/unix_socket.cc	2018-12-15 19:08:37.030799000 +0100
@@ -387,7 +387,8 @@
 
 void UnixSocket::ReadPeerCredentials() {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct ucred user_cred;
   socklen_t len = sizeof(user_cred);
   int res = getsockopt(*fd_, SOL_SOCKET, SO_PEERCRED, &user_cred, &len);
