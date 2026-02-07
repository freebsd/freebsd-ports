--- src/options.c.orig	Tue May 27 09:03:43 2003
+++ src/options.c	Wed Mar  3 00:47:28 2004
@@ -60,7 +60,7 @@
  * Minimum value is enforced. A warning is logged if greater than upper limit.
  */
 #define MINIMUM_INTERVAL  30    /* enforced */
-#define DEFAULT_INTERVAL 300
+#define DEFAULT_INTERVAL 550
 #define UPPER_INTERVAL   600    /* warning if exceeded */
 
 /* Macros */
@@ -79,7 +79,7 @@
  * These are the configuration options available.
  */
 char   cfg_authkey[AUTHKEY_REQUIRED_LEN + 1] = "";
-char   cfg_upserver[UPSERVER_MAXLEN + 1] = "uptimes.wonko.com";
+char   cfg_upserver[UPSERVER_MAXLEN + 1] = "uptimes.hostingwired.com";
 long int cfg_interval = DEFAULT_INTERVAL;
 char   cfg_pidfile[PIDFILE_MAXLEN + 1] = PIDFILE;
 char   cfg_proxyserver[PROXYSERVER_MAXLEN + 1] = "";
