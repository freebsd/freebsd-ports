--- src/freebsd.c.orig	Fri Sep  2 21:43:44 2005
+++ src/freebsd.c	Fri Sep  2 21:48:28 2005
@@ -590,6 +590,7 @@
 		return;
 }
 
+#if defined(i386) || defined(__i386__)
 #define APMDEV  "/dev/apm"
 #define APM_UNKNOWN     255
 
@@ -706,3 +707,4 @@
 
 	return out;
 }
+#endif
