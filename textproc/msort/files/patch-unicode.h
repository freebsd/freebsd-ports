--- unicode.h.orig	Mon Jan  8 03:33:05 2007
+++ unicode.h	Mon Jan 22 09:29:08 2007
@@ -1,3 +1,4 @@
+typedef unsigned short     UTF16;
 typedef unsigned long	UTF32;	/* at least 32 bits */
 typedef unsigned char	UTF8;	/* 8 bits */
 typedef unsigned char	Boolean; /* 0 or 1 */
