--- src/bbcp_NetAddr.C.orig	2015-01-14 12:13:30.000000000 -0800
+++ src/bbcp_NetAddr.C	2015-01-14 12:25:34.000000000 -0800
@@ -49,7 +49,7 @@
 #ifndef s6_addr32
 #if   defined(SUN)
 #define s6_addr32 _S6_un._S6_u32
-#elif defined(MACOS)
+#elif defined(MACOS) || defined(FREEBSD)
 #define s6_addr32 __u6_addr.__u6_addr32
 #endif
 #endif
