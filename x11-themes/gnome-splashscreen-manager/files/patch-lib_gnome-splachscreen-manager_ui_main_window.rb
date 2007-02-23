--- lib/gnome-splashscreen-manager/ui/main_window.rb.orig	Thu Feb 22 20:01:13 2007
+++ lib/gnome-splashscreen-manager/ui/main_window.rb	Thu Feb 22 20:01:34 2007
@@ -422,7 +422,7 @@
 
     #Add old splash screen
     def add_old_splash_screen
-      if (@old_splash_screen == "")
+      if (@old_splash_screen == "" || @old_splash_screen == nil)
         return
       end
 
