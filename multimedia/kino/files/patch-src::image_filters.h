--- src/image_filters.h.orig	Tue Apr 13 11:11:19 2004
+++ src/image_filters.h	Tue Apr 13 11:18:54 2004
@@ -27,7 +27,8 @@
 
 // C Includes
 
-#include <stdint.h>
+//#include <stdint.h>
+#include <sys/types.h>
 #include <gtk/gtk.h>
 
 /** Dummy interface for non-image encoding filters (only ImageFilterKeep should implement
