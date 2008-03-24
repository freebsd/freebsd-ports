--- lib/gnome-art/ui/main_window.rb.orig	2008-03-24 15:35:12.000000000 -0400
+++ lib/gnome-art/ui/main_window.rb	2008-03-24 16:30:50.000000000 -0400
@@ -407,7 +407,7 @@
 
             system(command)
 
-            system("gnome-theme-manager &")
+            system("gnome-appearance-properties &")
 
         end
       }
