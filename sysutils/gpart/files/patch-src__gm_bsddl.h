--- ./src/gm_bsddl.h.orig	2000-12-13 23:54:31.000000000 +0100
+++ ./src/gm_bsddl.h	2011-03-17 01:15:54.000000000 +0100
@@ -28,7 +28,7 @@
 
 #define BBSIZE		8192	/* size of boot area, with label */
 
-#ifdef __i386__
+#if defined(__i386__) || defined(__amd64__)
 #define LABELSECTOR	1			/* sector containing label */
 #define LABELOFFSET	0			/* offset of label in sector */
 #endif
