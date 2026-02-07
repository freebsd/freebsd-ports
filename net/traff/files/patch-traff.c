--- traff.c.orig	2009-11-10 20:55:07.000000000 -0500
+++ traff.c	2011-05-26 21:17:58.000000000 -0400
@@ -121,7 +121,7 @@
 /* The options we understand. */
 static struct argp_option options[] = {
 {"debug",  'd', 0,       0, "Produce debug output" },
-{"config",  'c', "FILE",       0, "Configuration File default: /etc/traff.conf" },
+{"config",  'c', "FILE",       0, "Configuration File default: %%PREFIX%%/etc/traff.conf" },
 { 0 }
 };
 
@@ -174,7 +174,7 @@
   
   /* Default values. */
   arguments.debug = 0;
-  arguments.config = "/etc/traff.conf";
+  arguments.config = "%%PREFIX%%/etc/traff.conf";
   
   /* Parse our arguments; every option seen by parse_opt will be
     reflected in arguments. */
