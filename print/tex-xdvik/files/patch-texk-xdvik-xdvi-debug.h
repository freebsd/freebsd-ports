--- texk/xdvik/xdvi-debug.h.orig	2013-03-31 05:28:21 UTC
+++ texk/xdvik/xdvi-debug.h
@@ -101,6 +101,7 @@
 #define DBG_GUI			131072
 #define DBG_FIND		262144
 #define DBG_FILES		524288
+#define DBG_PTEXFNT             1048576
 #define	DBG_ALL			(~DBG_BATCH)
 
 /* a mapping of numerical options to descriptive strings, defined in util.c */
