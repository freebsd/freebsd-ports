--- src/audio_transitions.h.orig	Mon Dec 22 06:43:05 2003
+++ src/audio_transitions.h	Tue Apr 13 11:22:03 2004
@@ -27,7 +27,8 @@
 
 // C Includes
 
-#include <stdint.h>
+//#include <stdint.h>
+#include <sys/types.h>
 #include <gtk/gtk.h>
 
 /** Public interface for all audio transition classes.
