--- src/knockd.c.orig	2021-04-24 16:54:37 UTC
+++ src/knockd.c
@@ -63,7 +63,7 @@
 extern int daemon(int, int);
 #endif
 
-static char version[] = "0.8";
+static char version[] = "#VERSION#";
 
 #define SEQ_TIMEOUT 25 /* default knock timeout in seconds */
 #define CMD_TIMEOUT 10 /* default timeout in seconds between start and stop commands */
@@ -163,7 +163,7 @@ int  o_daemon    = 0;
 int  o_lookup    = 0;
 int  o_skipIpV6  = 0;
 char o_int[32]           = "";		/* default (eth0) is set after parseconfig() */
-char o_cfg[PATH_MAX]     = "/etc/knockd.conf";
+char o_cfg[PATH_MAX]     = "%%PREFIX%%/etc/knockd.conf";
 char o_pidfile[PATH_MAX] = "/var/run/knockd.pid";
 char o_logfile[PATH_MAX] = "";
 
