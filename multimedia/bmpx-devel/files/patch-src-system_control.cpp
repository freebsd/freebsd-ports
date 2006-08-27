--- src/system_control.cpp.orig	Thu Aug 24 20:54:39 2006
+++ src/system_control.cpp	Thu Aug 24 20:57:02 2006
@@ -1309,7 +1309,8 @@
                                            int               n_added_rows,
                                            BmpSystemControl *control)
   {
-    g_signal_emit (G_OBJECT (control), signals[BMP_SYSTEM_CONTROL_SIGNAL_TRACKLIST_ITEMS_ADDED], 0);
+      g_signal_emit (G_OBJECT (control), signals[BMP_SYSTEM_CONTROL_SIGNAL_TRACKLIST_ITEMS_ADDED], 0,
+		      	added_rows, n_added_rows);  
   }
 
   void
