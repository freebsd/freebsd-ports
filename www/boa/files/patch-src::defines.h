--- src/defines.h.orig	Mon Nov 25 18:25:31 2002
+++ src/defines.h	Mon Nov 25 18:26:09 2002
@@ -27,7 +27,7 @@
 /***** Change this, or use -c on the command line to specify it *****/
 
 #ifndef SERVER_ROOT
-#define SERVER_ROOT "/etc/boa"
+#define SERVER_ROOT "%%PREFIX%%/etc"
 #endif
 
 /***** Change this via the CGIPath configuration value in boa.conf *****/
@@ -53,7 +53,7 @@
 
 #define REQUEST_TIMEOUT				60
 
-#define MIME_TYPES_DEFAULT                      "/etc/mime.types"
+#define MIME_TYPES_DEFAULT                      "%%PREFIX%%/etc/mime.types"
 #define CGI_MIME_TYPE                           "application/x-httpd-cgi"
 
 /***** CHANGE ANYTHING BELOW THIS LINE AT YOUR OWN PERIL *****/
