--- lib/gnome-splashscreen-manager/gnome_splashscreen_manager.rb.orig	Sun Apr 17 02:02:05 2005
+++ lib/gnome-splashscreen-manager/gnome_splashscreen_manager.rb	Sun Apr 17 02:06:02 2005
@@ -41,7 +41,7 @@
       puts "Create SplashScreen-File"
       splash_screens_file = File.new(file, File::CREAT|File::TRUNC|File::RDWR, 0644)
   
-      new_splash_screens_file = "<?xml version=\"1.0\"?>\n<splash_screens>\n</splash_screens>\n"
+      new_splash_screens_file = "<?xml version=\"1.0\"?>\n<splash_screens>\n%%SPLASHSCREENS%%\n<splash_screens>\n</splash_screens>\n"
 
       splash_screens_file.write(new_splash_screens_file)
     
