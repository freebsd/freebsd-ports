--- base/posix/unix_domain_socket_linux.cc.orig	2017-08-03 00:05:03.000000000 +0200
+++ base/posix/unix_domain_socket_linux.cc	2017-08-10 00:44:31.627900000 +0200
@@ -5,7 +5,10 @@
 #include "base/posix/unix_domain_socket_linux.h"
 
 #include <errno.h>
+#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
+#include <sys/ucred.h>
 #include <unistd.h>
 
 #include <vector>
@@ -25,6 +28,14 @@
 
 const size_t UnixDomainSocket::kMaxFileDescriptors = 16;
 
+#ifndef SCM_CREDENTIALS
+#  define SCM_CREDENTIALS      0X9001
+#endif
+
+#ifndef SO_PASSCRED
+#  define SO_PASSCRED          0x9002
+#endif
+
 #if !defined(OS_NACL_NONSFI)
 bool CreateSocketPair(ScopedFD* one, ScopedFD* two) {
   int raw_socks[2];
@@ -114,7 +125,7 @@
       CMSG_SPACE(sizeof(int) * kMaxFileDescriptors)
 #if !defined(OS_NACL_NONSFI)
       // The PNaCl toolchain for Non-SFI binary build does not support ucred.
-      + CMSG_SPACE(sizeof(struct ucred))
+      + CMSG_SPACE(sizeof(struct sockcred))
 #endif
       ;
   char control_buffer[kControlBufferSize];
@@ -145,9 +156,9 @@
       // SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
           cmsg->cmsg_type == SCM_CREDENTIALS) {
-        DCHECK_EQ(payload_len, sizeof(struct ucred));
+        DCHECK_EQ(payload_len, sizeof(struct sockcred));
         DCHECK_EQ(pid, -1);
-        pid = reinterpret_cast<struct ucred*>(CMSG_DATA(cmsg))->pid;
+        pid = getpid();
       }
 #endif
     }
