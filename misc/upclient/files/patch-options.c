--- src/options.c.orig	Wed Oct  2 06:50:49 2002
+++ src/options.c	Sat Oct 19 22:54:06 2002
@@ -55,7 +55,7 @@
  */
 char cfg_authkey[AUTHKEY_REQUIRED_LEN+1]	= "";
 char cfg_upserver[UPSERVER_MAXLEN+1]		= "uptimes.wonko.com";
-int  cfg_interval				= 300;
+int  cfg_interval				= 550;
 char cfg_pidfile[PIDFILE_MAXLEN+1]		= PIDFILE;
 char cfg_proxyserver[PROXYSERVER_MAXLEN+1]	= "";
 int  cfg_udpport				= 49153;
