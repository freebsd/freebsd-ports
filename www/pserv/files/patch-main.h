--- main.h.orig	Fri Sep 19 00:36:03 2003
+++ main.h	Thu Oct 16 13:52:18 2003
@@ -24,11 +24,12 @@
 
 
 /* --- CPP parsing options --- */
-#define PRINTF_DEBUG          /* enable this to print some debugging messages */
+#undef PRINTF_DEBUG          /* enable this to print some debugging messages */
 #undef ON_THE_FLY_CONVERSION /* enable this for line ending conversion */
 #undef BRAIN_DEAD_CAST       /* if your compiler is brainwashed and does not cast standard types.h structures */
 #define FORKING_SERVER       /* enables to fork for every request */
 #define AUTO_INDEX           /* enables auto-index of directories */
+#define PHP                  /* enables transparent PHP support */
 
 /* --- Configure options --- */
 #define CONFIG_FILE_NAME "pserv.conf"
@@ -39,19 +40,19 @@
 #define MIME_TYPE_DEFAULT "application/octet-stream"
 
 /* configuration file location */
-#define DEFAULT_CONFIG_LOCATION "/export/home/multix/pserv/"
-//#define DEFAULT_CONFIG_LOCATION "/Users/multix/Documents/code/pserv/"
+#define DEFAULT_CONFIG_LOCATION "/usr/local/etc/"
 
 /* hard-wired defaults, if loading of config file fails */
-#define DEFAULT_PORT 2000
+#define DEFAULT_PORT 80
 #define DEFAULT_MAX_CHILDREN 5
-#define DEFAULT_DOCS_LOCATION "/export/home/multix/public_html"
+#define DEFAULT_DOCS_LOCATION "/usr/local/www/data"
 #define DEFAULT_FILE_NAME "index.html"
 #define DEFAULT_SEC_TO 1
 #define DEFAULT_USEC_TO 100
-#define DEFAULT_LOG_FILE "/export/home/multix/pserv/pserv.log"
-#define DEFAULT_MIME_FILE "/export/home/multix/pserv/mime_types.dat"
-#define DEFAULT_CGI_ROOT "/export/home/multix/public_html/cgi-bin"
+#define DEFAULT_LOG_FILE "/var/log/pserv.log"
+#define DEFAULT_MIME_FILE "/usr/local/etc/mime.types"
+#define DEFAULT_PHP_FILE "/usr/local/bin/php"
+#define DEFAULT_CGI_ROOT "/usr/local/www/cgi-bin"
 #define DEFAULT_SERVER_NAME "localhost"
 
 /* amount of connections queued in listening */
@@ -120,9 +121,11 @@
 #define ADDRESS_LEN 16
 #define METHOD_LEN 16
 #define PROTOCOL_LEN 16
+#define CONTENT_TYPE_LEN 256
 #define USER_AGENT_LEN 256
 #define MAX_QUERY_STRING_LEN 1024
 #define MAX_PATH_LEN 1024
+#define MAX_COOKIE_LEN 4096
 
 struct request
 {
@@ -133,7 +136,9 @@
     char protocolVersion[PROTOCOL_LEN+1];
     int keepAlive;
     char userAgent[USER_AGENT_LEN+1];
+    char cookie[MAX_COOKIE_LEN+1];
     long int contentLength;
+    char contentType[CONTENT_TYPE_LEN+1];
     char rest[BUFFER_SIZE+1];
 };
 
