--- src/bbcp_NetAddrInfo.C.orig	2015-01-14 12:14:07.000000000 -0800
+++ src/bbcp_NetAddrInfo.C	2015-01-14 12:26:37.000000000 -0800
@@ -67,7 +67,7 @@
 #ifndef s6_addr32
 #if   defined(SUN)
 #define s6_addr32 _S6_un._S6_u32
-#elif defined(MACOS)
+#elif defined(MACOS) || defined(FREEBSD)
 #define s6_addr32 __u6_addr.__u6_addr32
 #endif
 #endif
