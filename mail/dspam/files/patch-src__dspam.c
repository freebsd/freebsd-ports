--- src/dspam.c.orig	2012-04-11 11:48:33.000000000 -0700
+++ src/dspam.c	2014-09-23 19:43:09.688194417 -0700
@@ -4194,7 +4194,7 @@
 
     pidfile = _ds_read_attribute(agent_config, "ServerPID");
     if ( pidfile == NULL )
-      pidfile = "/var/run/dspam/dspam.pid";
+      pidfile = "/var/run/dspam.pid";
 
     if (pidfile) {
       FILE *file;
