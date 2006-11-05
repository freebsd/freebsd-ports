--- ../glib/src/lib/mkmf-gnome2.rb.orig	Fri Nov  3 18:58:17 2006
+++ ../glib/src/lib/mkmf-gnome2.rb	Fri Nov  3 18:58:45 2006
@@ -184,6 +184,10 @@
 def make_version_header(app_name, pkgname, dir = "src")
   version = PKGConfig.modversion(pkgname).split(/\./)
 
+  (0..2).each do |v|
+    version[v] = "0" unless version[v]
+  end
+
   filename = "rb#{app_name.downcase}version.h"
 
   puts "creating #{filename}"
