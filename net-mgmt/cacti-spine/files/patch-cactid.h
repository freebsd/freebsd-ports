--- cactid.h.orig	Sat Feb 26 21:46:10 2005
+++ cactid.h	Sat Feb 26 21:46:34 2005
@@ -45,8 +45,8 @@
 
 /* locations to search for the config file */
 #define CONFIG_PATHS 5
-#define CONFIG_PATH_1 ""
-#define CONFIG_PATH_2 "/etc/"
+#define CONFIG_PATH_1 "%%PREFIX%%/etc/"
+#define CONFIG_PATH_2 ""
 #define CONFIG_PATH_3 "/cygdrive/c/wwwroot/cacti"
 #define CONFIG_PATH_4 "/cygdrive/c/webroot/cacti"
 #define CONFIG_PATH_5 "/cygdrive/c/inetpub/wwwroot/cacti"
