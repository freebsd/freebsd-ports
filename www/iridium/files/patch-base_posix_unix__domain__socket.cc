--- base/posix/unix_domain_socket.cc.orig	2018-01-04 21:05:38.000000000 +0100
+++ base/posix/unix_domain_socket.cc	2018-01-06 12:44:56.681201000 +0100
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
@@ -28,6 +31,14 @@
 
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
@@ -150,7 +161,7 @@
 #if !defined(OS_NACL_NONSFI) && !defined(OS_MACOSX)
       // The PNaCl toolchain for Non-SFI binary build and macOS do not support
       // ucred. macOS supports xucred, but this structure is insufficient.
-      + CMSG_SPACE(sizeof(struct ucred))
+      + CMSG_SPACE(sizeof(struct cmsgcred))
 #endif  // OS_NACL_NONSFI or OS_MACOSX
       ;
   char control_buffer[kControlBufferSize];
@@ -180,9 +191,9 @@
       // SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
           cmsg->cmsg_type == SCM_CREDENTIALS) {
-        DCHECK_EQ(payload_len, sizeof(struct ucred));
+        DCHECK_EQ(payload_len, sizeof(struct cmsgcred));
         DCHECK_EQ(pid, -1);
-        pid = reinterpret_cast<struct ucred*>(CMSG_DATA(cmsg))->pid;
+        pid = getpid();
       }
 #endif  // !defined(OS_NACL_NONSFI) && !defined(OS_MACOSX)
     }
