--- mupdisp/dispttyp.h.orig	Sat Jun 22 12:30:53 2002
+++ mupdisp/dispttyp.h	Wed Nov 27 23:28:55 2002
@@ -9,7 +9,7 @@
  * Support for other terminal types could be added in the future. */
 
 #ifdef i386
-#if !defined(linux) && !defined(__EMX__)
+#if !defined(linux) && !defined(__EMX__) && !defined(__FreeBSD__)
 #define AT386	1
 #endif
 #endif
