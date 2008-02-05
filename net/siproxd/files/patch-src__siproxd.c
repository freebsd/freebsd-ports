--- src/siproxd.c.orig	Sat Jan 19 17:06:51 2008
+++ src/siproxd.c	Mon Feb  4 16:42:25 2008
@@ -182,10 +182,15 @@
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
