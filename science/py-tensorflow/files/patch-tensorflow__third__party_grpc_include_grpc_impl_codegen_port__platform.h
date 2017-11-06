--- tensorflow_third_party/grpc/include/grpc/impl/codegen/port_platform.h.orig	2017-06-12 12:45:01 UTC
+++ tensorflow_third_party/grpc/include/grpc/impl/codegen/port_platform.h
@@ -131,7 +131,7 @@
 #define GPR_POSIX_SOCKETUTILS 1
 #define GPR_SUPPORT_CHANNELS_FROM_FD 1
 #define GPR_HAVE_UNIX_SOCKET 1
-#define GPR_HAVE_IP_PKTINFO 1
+//#define GPR_HAVE_IP_PKTINFO 1
 #define GPR_HAVE_IPV6_RECVPKTINFO 1
 #define GPR_LINUX_ENV 1
 #define GPR_POSIX_FILE 1
@@ -176,7 +176,7 @@
 #define GPR_SUPPORT_CHANNELS_FROM_FD 1
 #define GPR_HAVE_MSG_NOSIGNAL 1
 #define GPR_HAVE_UNIX_SOCKET 1
-#define GPR_HAVE_IP_PKTINFO 1
+//#define GPR_HAVE_IP_PKTINFO 1
 #define GPR_HAVE_IPV6_RECVPKTINFO 1
 #elif defined(__linux__)
 #define GPR_POSIX_CRASH_HANDLER 1
@@ -202,7 +202,7 @@
 #define GPR_POSIX_SOCKETADDR 1
 #define GPR_SUPPORT_CHANNELS_FROM_FD 1
 #define GPR_HAVE_UNIX_SOCKET 1
-#define GPR_HAVE_IP_PKTINFO 1
+//#define GPR_HAVE_IP_PKTINFO 1
 #define GPR_HAVE_IPV6_RECVPKTINFO 1
 #ifdef __GLIBC_PREREQ
 #if __GLIBC_PREREQ(2, 9)
@@ -269,7 +269,7 @@
 #define GPR_SUPPORT_CHANNELS_FROM_FD 1
 #define GPR_HAVE_SO_NOSIGPIPE 1
 #define GPR_HAVE_UNIX_SOCKET 1
-#define GPR_HAVE_IP_PKTINFO 1
+//#define GPR_HAVE_IP_PKTINFO 1
 #ifdef _LP64
 #define GPR_ARCH_64 1
 #else /* _LP64 */
@@ -301,7 +301,7 @@
 #define GPR_SUPPORT_CHANNELS_FROM_FD 1
 #define GPR_HAVE_SO_NOSIGPIPE 1
 #define GPR_HAVE_UNIX_SOCKET 1
-#define GPR_HAVE_IP_PKTINFO 1
+//#define GPR_HAVE_IP_PKTINFO 1
 #define GPR_HAVE_IPV6_RECVPKTINFO 1
 #ifdef _LP64
 #define GPR_ARCH_64 1
