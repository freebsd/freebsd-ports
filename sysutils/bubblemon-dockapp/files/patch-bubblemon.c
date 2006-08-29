--- bubblemon.c.orig	Wed Oct  1 02:37:32 2003
+++ bubblemon.c	Tue Aug 29 01:10:47 2006
@@ -912,7 +912,7 @@
 
     while (i--) {
 	unsigned char *rgb = (unsigned char *) &col[*buf_ptr++];
-#if (defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && (__BYTE_ORDER == __LITTLE_ENDIAN)) || defined(_LITTLE_ENDIAN) || (BYTE_ORDER == LITTLE_ENDIAN)
+#if (defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && (__BYTE_ORDER == __LITTLE_ENDIAN)) || (defined(_LITTLE_ENDIAN) && !defined(__FreeBSD__)) || (defined(BYTE_ORDER) && defined(LITTLE_ENDIAN) && (BYTE_ORDER == LITTLE_ENDIAN))
 	*ptr++ = rgb[2];
 	*ptr++ = rgb[1];
 	*ptr++ = rgb[0];
