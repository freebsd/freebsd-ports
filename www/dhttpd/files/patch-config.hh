--- src/config.hh.orig	Mon Jun 24 15:21:37 2002
+++ src/config.hh	Mon Jun 24 15:23:14 2002
@@ -1,17 +1,17 @@
 /* Set this as the user id number you want dhttpd to use when    *
  * starting it as root.  You can get this info from /etc/passwd. */
-#define UID		65534
+#define UID		80
 
 /* Set this to the proper group id number of UID above.          */
-#define GID		65534
+#define GID		80
 
 /* Set your default port number.  If you aren't running as       *
  * root, you must use a value >= 1024, such as 8080.             */
 #define DEFAULTPORT	80
 
 /* This is the directory where the web pages are located.        */
-#define WEBDIRPREFIX	"/var/www"
+#define WEBDIRPREFIX	"%%PREFIX%%/www/data"
 
 /* This defines the maximum number of child processes (i.e.      *
  * maximum sockets being serviced by dhttpd).                    */
-#define MAXCHILDPROC	100
+#define MAXCHILDPROC	2048
