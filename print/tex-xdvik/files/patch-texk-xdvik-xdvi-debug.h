--- texk/xdvik/xdvi-debug.h.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/xdvi-debug.h	2015-01-31 21:02:18.000000000 +0900
@@ -101,6 +101,7 @@
 #define DBG_GUI			131072
 #define DBG_FIND		262144
 #define DBG_FILES		524288
+#define DBG_PTEXFNT             1048576
 #define	DBG_ALL			(~DBG_BATCH)
 
 /* a mapping of numerical options to descriptive strings, defined in util.c */
