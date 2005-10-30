--- cactid.h.orig	Tue Oct 11 23:13:48 2005
+++ cactid.h	Sun Oct 30 14:15:22 2005
@@ -55,7 +55,7 @@
 /* locations to search for the config file */
 #define CONFIG_PATHS 2
 #define CONFIG_PATH_1 ""
-#define CONFIG_PATH_2 "/etc/"
+#define CONFIG_PATH_2 "%%PREFIX%%/etc/"
 
 /* config file defaults */
 #define DEFAULT_CONF_FILE "cactid.conf"
