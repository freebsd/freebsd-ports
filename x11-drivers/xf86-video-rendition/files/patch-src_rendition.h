--- src/rendition.h.orig	2012-07-16 02:42:28 UTC
+++ src/rendition.h
@@ -28,9 +28,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 /* All drivers using the mi colormap manipulation need this */
 #include "micmap.h"
 
