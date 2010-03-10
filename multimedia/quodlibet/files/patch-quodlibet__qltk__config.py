--- quodlibet/qltk/config.py.orig	2010-02-18 03:01:37.000000000 -0500
+++ quodlibet/qltk/config.py	2010-02-18 03:01:59.000000000 -0500
@@ -54,7 +54,3 @@
 
     def __toggled(self, section, option):
         config.set(section, option, str(bool(self.get_active())).lower())
-
-    
-
-class ConfigCheckButton(gtk.CheckButton)
