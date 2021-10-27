--- base/posix/unix_domain_socket.cc.orig	2021-09-14 01:51:47 UTC
+++ base/posix/unix_domain_socket.cc
@@ -5,7 +5,10 @@
 #include "base/posix/unix_domain_socket.h"
 
 #include <errno.h>
+#include <sys/param.h>
 #include <sys/socket.h>
+#include <sys/types.h>
+#include <sys/ucred.h>
 #if !defined(OS_NACL_NONSFI)
 #include <sys/un.h>
 #endif
@@ -28,6 +31,14 @@ namespace base {
 
 const size_t UnixDomainSocket::kMaxFileDescriptors = 16;
 
+#ifndef SCM_CREDENTIALS
+#  define SCM_CREDENTIALS  0x9001
+#endif
+
+#ifndef SO_PASSCRED
+#  define SO_PASSCRED      0x9002
+#endif
+
 #if !defined(OS_NACL_NONSFI)
 bool CreateSocketPair(ScopedFD* one, ScopedFD* two) {
   int raw_socks[2];
@@ -150,7 +161,7 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
 #if !defined(OS_NACL_NONSFI) && !defined(OS_APPLE)
       // The PNaCl toolchain for Non-SFI binary build and macOS do not support
       // ucred. macOS supports xucred, but this structure is insufficient.
-      + CMSG_SPACE(sizeof(struct ucred))
+      + CMSG_SPACE(sizeof(struct cmsgcred))
 #endif  // !defined(OS_NACL_NONSFI) && !defined(OS_APPLE)
       ;
   char control_buffer[kControlBufferSize];
@@ -180,9 +191,9 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
       // SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
           cmsg->cmsg_type == SCM_CREDENTIALS) {
-        DCHECK_EQ(payload_len, sizeof(struct ucred));
+        DCHECK_EQ(payload_len, sizeof(struct cmsgcred));
         DCHECK_EQ(pid, -1);
-        pid = reinterpret_cast<struct ucred*>(CMSG_DATA(cmsg))->pid;
+        pid = getpid();
       }
 #endif  // !defined(OS_NACL_NONSFI) && !defined(OS_APPLE)
     }
