--- mod_watch.c.orig	Wed Nov 27 15:20:42 2002
+++ mod_watch.c	Thu Jun  3 13:54:49 2004
@@ -41,6 +41,10 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#ifdef INET6
+#error mod_watch is not IPv6-aware.
+#endif
+
 #ifndef SPOOLDIR
 #define SPOOLDIR		"/var/spool/mod_watch/"
 #endif
@@ -74,7 +78,7 @@
 
 #define MODULE			"mod_watch"
 #define AUTHOR			"achowe@snert.com"
-#define VERSION			"3.17"
+#define VERSION			"3.18"
 #define COPYRIGHT_DATE		"2001, 2002"
 
 #include "httpd.h"
