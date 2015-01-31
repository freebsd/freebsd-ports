--- texk/xdvik/version.h.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/version.h	2015-01-31 21:02:18.000000000 +0900
@@ -3,6 +3,7 @@
 #define VERSION_H_
 
 #define XDVI_VERSION "22.87"
+#define JPVERSION "j1.42-freebsd"
 
 #ifdef MOTIF
 #define XDVI_GUI "(Motif toolkit)"
@@ -13,7 +14,7 @@
 #define	XDVIK_PROGNAME "xdvik"
 #define	XDVI_PROGNAME "xdvi"
 
-#define XDVI_VERSION_INFO XDVI_VERSION" "XDVI_GUI
-#define XDVI_TERSE_VERSION_INFO XDVI_VERSION
+#define XDVI_VERSION_INFO XDVI_VERSION" "JPVERSION" "XDVI_GUI
+#define XDVI_TERSE_VERSION_INFO XDVI_VERSION" "JPVERSION
 
 #endif /* VERSION_H_ */
