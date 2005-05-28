--- sources/main.h.orig	Mon May 16 23:08:30 2005
+++ sources/main.h	Sat May 28 10:47:09 2005
@@ -27,6 +27,8 @@
 
 #define AUTO_INDEX              /* enables auto-index of directories */
 #define SOCKADDR_REUSE          /* enables reuse oth the socket (quick relaunch) */
+#define LOG                     /* enable logging to file */
+#define PHP                     /* enables transparent PHP support */
 
 
 /* --- Configure options --- */
@@ -38,18 +40,19 @@
 #define MIME_TYPE_DEFAULT   "application/octet-stream"
 
 /* configuration file location */
-#define DEFAULT_CONFIG_LOCATION "/usr/local/etc/pserv/"
+#define DEFAULT_CONFIG_LOCATION "%%PREFIX%%/etc/pserv/"
 
 /* hard-wired defaults, if loading of config file fails */
-#define DEFAULT_PORT	    	2000
+#define DEFAULT_PORT	    	80
 #define DEFAULT_MAX_CHILDREN	5
-#define DEFAULT_DOCS_LOCATION	"/usr/local/var/www"
+#define DEFAULT_DOCS_LOCATION	"%%PREFIX%%/www/data"
 #define DEFAULT_FILE_NAME   	"index.html"
 #define DEFAULT_SEC_TO	    	1
 #define DEFAULT_USEC_TO     	100
-#define DEFAULT_LOG_FILE    	"/usr/local/var/log/pserv.log"
-#define DEFAULT_MIME_FILE   	"/usr/local/etc/pserv/mime_types.dat"
-#define DEFAULT_CGI_ROOT    	"/usr/local/var/www/cgi-bin"
+#define DEFAULT_LOG_FILE    	"/var/log/pserv.log"
+#define DEFAULT_MIME_FILE   	"%%PREFIX%%/etc/mime.types.pserv"
+#define DEFAULT_PHP_FILE    	"%%LOCALBASE%%/bin/php"
+#define DEFAULT_CGI_ROOT    	"%%PREFIX%%/www/cgi-bin"
 #define DEFAULT_SERVER_NAME 	"localhost"
 
 /* amount of connections queued in listening */
@@ -122,8 +125,10 @@
 #define ADDRESS_LEN 	    	16
 #define METHOD_LEN  	    	16
 #define PROTOCOL_LEN	    	16
+#define CONTENT_TYPE_LEN   	256
 #define USER_AGENT_LEN	    	256
 #define MAX_QUERY_STRING_LEN	1024
+#define MAX_COOKIE_LEN     	4096
 
 /* ------ Structures ------- */
 /* we use +1 to be safe with handling the end-of-string */
@@ -141,7 +146,9 @@
     char     protocolVersion[PROTOCOL_LEN+1];
     int      keepAlive;
     char     userAgent[USER_AGENT_LEN+1];
+    char     cookie[MAX_COOKIE_LEN+1];
     long int contentLength;
+    char     contentType[CONTENT_TYPE_LEN+1];
     char     rest[BUFFER_SIZE+1];
 };
 
