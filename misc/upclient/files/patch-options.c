--- src/options.c.orig	Sat Jun 16 21:15:04 2001
+++ src/options.c	Sun Nov 18 17:40:06 2001
@@ -16,9 +16,9 @@
  * These are the configuration options available.
  */
 char cfg_authkey[AUTHKEY_REQUIRED_LEN+1]	= "";
-char cfg_upserver[UPSERVER_MAXLEN+1]		= "data.uptimes.net";
-int  cfg_interval				= 120;
-char cfg_pidfile[PIDFILE_MAXLEN+1]		= ".upclient.pid";
+char cfg_upserver[UPSERVER_MAXLEN+1]		= "uptimes.wonko.com";
+int  cfg_interval				= 550;
+char cfg_pidfile[PIDFILE_MAXLEN+1]		= "/var/run/upclient.pid";
 char cfg_proxyserver[PROXYSERVER_MAXLEN+1]	= "";
 int  cfg_proxyport				= 8080;
 char cfg_proxyuser[PROXYUSER_MAXLEN+1]		= "";
