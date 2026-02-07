--- usuals.h.orig	Mon Jan 12 00:13:07 1998
+++ usuals.h	Sun Dec  8 11:34:50 2002
@@ -8,7 +8,7 @@
 typedef byte *byteptr;	/* pointer to byte */
 typedef char *string;	/* pointer to ASCII character string */
 typedef unsigned short word16;	/* values are 0-65535 */
-#ifdef __alpha
+#if defined(__alpha) || defined(__sparc64__) || defined(__ia64__) || defined(__amd64__)
 typedef unsigned int word32;	/* values are 0-4294967295 */
 #else
 typedef unsigned long word32;	/* values are 0-4294967295 */
