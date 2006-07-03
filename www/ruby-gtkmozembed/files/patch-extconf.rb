--- extconf.rb.orig	Sun Jul  2 19:15:05 2006
+++ extconf.rb	Sun Jul  2 19:19:25 2006
@@ -23,8 +23,7 @@
 PKGConfig.have_package(PACKAGE_ID)
 setup_win32(PACKAGE_NAME)
 
-mozpath = PKGConfig.libs_only_L(PACKAGE_ID)
-mozpath.strip!.sub!(/^-L/, "")
+mozpath = "%%GECKO_PATH%%"
 
 if mozpath 
   # please comment the CFLAGS line if you don't want a default comp_path
