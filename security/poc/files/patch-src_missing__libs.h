
$FreeBSD$

--- src/missing_libs.h.orig	Thu Jul 25 17:11:57 2002
+++ src/missing_libs.h	Thu Jul 25 17:12:25 2002
@@ -46,7 +46,7 @@
 #define __bswap_constant_16(x) \
      ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))
 
-#if defined __GNUC__ && __GNUC__ >= 2
+#if defined __i386__ && defined __GNUC__ && __GNUC__ >= 2
 # define __bswap_16(x) \
      (__extension__                                                           \
       ({ register unsigned short int __v;                                     \
