--- src/libguppiplot/guppi-root-group-item.c.orig	Mon Sep  6 15:01:23 2004
+++ src/libguppiplot/guppi-root-group-item.c	Mon Sep  6 15:01:35 2004
@@ -548,6 +548,7 @@
     return motion_notify_event (root, &(ev->motion));
 
   default:
+  ;
   }
 
   return FALSE;
@@ -777,6 +778,7 @@
   case ROOT_GROUP_RESIZE_NONE:
   default:
     /* insure we do nothing */
+    ;
   }
 
   if (please_resize_canvas)
