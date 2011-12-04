--- xpp.cxx.orig	2004-12-06 11:00:04.000000000 -0800
+++ xpp.cxx	2011-12-03 22:11:00.788941301 -0800
@@ -2500,7 +2500,7 @@
     // Redraw the destination menu in the main window
 
     printerPack->parent()->redraw();
-    printerPack->draw();
+    printerPack->redraw();
   
   }
 
@@ -2674,7 +2674,7 @@
   // Redraw the destination menu in the main window
 
   printerPack->parent()->redraw();
-  printerPack->draw();
+  printerPack->redraw();
   
   return(dest_index);
 }
