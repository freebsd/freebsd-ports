--- datatype/h263/codec/video/hvdecode.c.orig	Wed Feb 19 14:47:48 2003
+++ datatype/h263/codec/video/hvdecode.c	Sat May 22 00:27:16 2004
@@ -38,7 +38,7 @@
 #include <stdio.h>
 #include <stddef.h>
 #include <string.h>
-#ifdef FOR_MAC
+#if defined (FOR_MAC)  || defined (_FREEBSD)
 #include <stdlib.h>
 #else
 #include <malloc.h>
