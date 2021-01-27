--- third_party/perfetto/src/base/unix_socket.cc.orig	2021-01-18 21:31:50 UTC
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -38,7 +38,7 @@
 #include "perfetto/ext/base/string_utils.h"
 #include "perfetto/ext/base/utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #include <sys/ucred.h>
 #endif
 
@@ -630,7 +630,7 @@ void UnixSocket::ReadPeerCredentials() {
   if (sock_raw_.family() != SockFamily::kUnix)
     return;
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   struct ucred user_cred;
   socklen_t len = sizeof(user_cred);
