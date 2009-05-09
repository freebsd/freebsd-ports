--- ./fwcutter.h.orig	2008-02-13 11:46:26.000000000 -0600
+++ ./fwcutter.h	2009-05-07 01:28:47.979870488 -0500
@@ -12,7 +12,7 @@
 typedef uint16_t be16_t; /* Big-endian 16bit */
 typedef uint32_t be32_t; /* Big-endian 32bit */
 
-#ifdef __DragonFly__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 #define bswap_16	bswap16
 #define bswap_32	bswap32
 #endif
