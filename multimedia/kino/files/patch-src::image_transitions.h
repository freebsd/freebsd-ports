--- src/image_transitions.h.orig	Mon Dec 22 06:42:29 2003
+++ src/image_transitions.h	Tue Apr 13 11:20:19 2004
@@ -27,7 +27,8 @@
 
 // C Includes
 
-#include <stdint.h>
+//#include <stdint.h>
+#include <sys/types.h>
 #include <gtk/gtk.h>
 
 /** Public interface for all image transition classes.
