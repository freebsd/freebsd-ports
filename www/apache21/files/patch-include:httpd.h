--- include/httpd.h.orig	Sat Apr  7 09:11:19 2001
+++ include/httpd.h	Sat Apr  7 09:08:43 2001
@@ -127,7 +127,7 @@
 /* Set default for OS/2 file system */
 #define DOCUMENT_LOCATION  HTTPD_ROOT "/docs"
 #else
-#define DOCUMENT_LOCATION  HTTPD_ROOT "/htdocs"
+#define DOCUMENT_LOCATION  HTTPD_ROOT "/www/data"
 #endif
 #endif /* DOCUMENT_LOCATION */
 
@@ -144,7 +144,7 @@
 #if defined(OS2) || defined(WIN32)
 #define DEFAULT_ERRORLOG "logs/error.log"
 #else
-#define DEFAULT_ERRORLOG "logs/error_log"
+#define DEFAULT_ERRORLOG "/var/log/httpd-error.log"
 #endif
 #endif /* DEFAULT_ERRORLOG */
 
@@ -160,7 +160,7 @@
 
 /* The name of the server config file */
 #ifndef SERVER_CONFIG_FILE
-#define SERVER_CONFIG_FILE "conf/httpd.conf"
+#define SERVER_CONFIG_FILE "etc/apache/httpd.conf"
 #endif
 
 /* Whether we should enable rfc1413 identity checking */
@@ -247,7 +247,7 @@
 
 /* The name of the MIME types file */
 #ifndef AP_TYPES_CONFIG_FILE
-#define AP_TYPES_CONFIG_FILE "conf/mime.types"
+#define AP_TYPES_CONFIG_FILE "etc/apache/mime.types"
 #endif
 
 /*
