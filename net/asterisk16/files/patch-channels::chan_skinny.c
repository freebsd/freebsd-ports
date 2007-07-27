
$FreeBSD$

--- channels/chan_skinny.c.orig
+++ channels/chan_skinny.c
@@ -107,7 +107,7 @@
 #define htolel(x) (x)
 #define htoles(x) (x)
 #else
-#if defined(SOLARIS) || defined(__Darwin__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(SOLARIS) || defined(__Darwin__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define __bswap_16(x) \
 	((((x) & 0xff00) >> 8) | \
 	 (((x) & 0x00ff) << 8))
