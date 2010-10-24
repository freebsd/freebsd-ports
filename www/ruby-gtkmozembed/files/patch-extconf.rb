--- extconf.rb.orig	2010-10-24 14:12:43.000000000 -0700
+++ extconf.rb	2010-10-24 14:12:53.000000000 -0700
@@ -57,6 +57,7 @@
 
 mozilla_library_path = PKGConfig.libs_only_L(package_id)
 mozilla_path = mozilla_library_path.strip.sub(/^-L/, "")
+$CFLAGS << " " + PKGConfig.cflags(package_id) + " " + PKGConfig.cflags("libxul")
 
 if mozilla_path
   # please comment the CFLAGS line if you don't want a default comp_path
