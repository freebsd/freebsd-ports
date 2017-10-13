--- third_party/grpc/src/include/grpc/impl/codegen/port_platform.h.orig	2017-09-14 17:36:37 UTC
+++ third_party/grpc/src/include/grpc/impl/codegen/port_platform.h
@@ -301,7 +301,8 @@
 #define GPR_SUPPORT_CHANNELS_FROM_FD 1
 #define GPR_HAVE_SO_NOSIGPIPE 1
 #define GPR_HAVE_UNIX_SOCKET 1
-#define GPR_HAVE_IP_PKTINFO 1
+#define GPR_HAVE_IP_PKTINFO 0
+#undef GPR_HAVE_IP_PKTINFO
 #define GPR_HAVE_IPV6_RECVPKTINFO 1
 #ifdef _LP64
 #define GPR_ARCH_64 1
