error: invalid suffix on literal; C++11 requires a space between literal and identifier 
   [-Wreserved-user-defined-literal]
   #define VERSION_NAME "uim-xim under the way! Version "PACKAGE_VERSION"\n"

--- xim/main.cpp.orig	2018-01-17 10:10:47 UTC
+++ xim/main.cpp
@@ -65,7 +65,7 @@ int g_option_mask;
 int scr_width, scr_height;
 int host_byte_order;
 
-#define VERSION_NAME "uim-xim under the way! Version "PACKAGE_VERSION"\n"
+#define VERSION_NAME "uim-xim under the way! Version " PACKAGE_VERSION "\n"
 const char *version_name=VERSION_NAME;
 const char *usage=
 "--help , --version :Show usage or version\n"
