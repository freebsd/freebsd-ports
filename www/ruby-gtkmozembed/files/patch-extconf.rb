--- extconf.rb.orig	Fri Dec  1 02:00:22 2006
+++ extconf.rb	Fri Dec  1 03:37:15 2006
@@ -40,8 +40,7 @@
 PKGConfig.have_package(package_id)
 setup_win32(PACKAGE_NAME)
 
-mozpath = PKGConfig.libs_only_L(package_id)
-mozpath.strip!.sub!(/^-L/, "")
+mozpath = "%%GECKO_PATH%%"
 
 if mozpath 
   # please comment the CFLAGS line if you don't want a default comp_path
