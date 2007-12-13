--- src/siproxd.c.orig	Fri Jun  8 21:41:47 2007
+++ src/siproxd.c	Wed Nov 14 12:26:19 2007
@@ -181,10 +181,15 @@
 /*
  * Init stuff
  */
-   INFO(PACKAGE"-"VERSION"-"BUILDSTR" "UNAME" starting up");
-
    /* read the config file */
    if (read_config(configfile, config_search) == STS_FAILURE) exit(1);
+
+   /* Don't log to stderr if daemonizing is intended. */
+   if (configuration.daemonize) {
+     log_set_stderr(0);
+   }
+
+   INFO(PACKAGE"-"VERSION"-"BUILDSTR" "UNAME" starting up");
 
    /* if a debug level > 0 has been given on the commandline use its
       value and not what is in the config file */
