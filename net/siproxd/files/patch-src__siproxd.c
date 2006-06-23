--- src/siproxd.c.orig	Sun Jun 18 18:28:20 2006
+++ src/siproxd.c	Wed Jun 21 09:06:10 2006
@@ -177,11 +177,16 @@
 /*
  * Init stuff
  */
-   INFO(PACKAGE"-"VERSION"-"BUILDSTR" "UNAME" starting up");
-
    /* read the config file */
    if (read_config(configfile, config_search) == STS_FAILURE) exit(1);
 
+   /* Don't log to stderr if daemonizing is intended. */
+   if (configuration.daemonize) {
+      log_set_stderr(0);
+   }
+
+   INFO(PACKAGE"-"VERSION"-"BUILDSTR" "UNAME" starting up");
+
    /* if a debug level > 0 has been given on the commandline use its
       value and not what is in the config file */
    if (cmdline_debuglevel != 0) {
@@ -212,7 +217,6 @@
       setsid();
       if (fork()!=0) exit(0);
 
-      log_set_stderr(0);
       INFO("daemonized, pid=%i", getpid());
    }
 
