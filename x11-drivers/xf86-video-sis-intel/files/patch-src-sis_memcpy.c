--- src/sis_memcpy.c.orig	2007-05-02 05:13:01.000000000 +0400
+++ src/sis_memcpy.c	2008-05-27 03:01:00.000000000 +0400
@@ -844,9 +844,7 @@
 
 #ifdef SISCHECKOSSSE
 
-#ifndef XFree86LOADER
 #include <setjmp.h>
-#endif
 
 static jmp_buf sigill_return;
 
