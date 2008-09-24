--- src/siproxd.c.orig	2008-02-04 21:38:47.000000000 +0100
+++ src/siproxd.c	2008-08-29 19:37:53.000000000 +0200
@@ -226,8 +226,6 @@
 /*
  * Init stuff
  */
-   INFO(PACKAGE"-"VERSION"-"BUILDSTR" "UNAME" starting up");
-
    /* read the config file */
    if (read_config(configfile, config_search, main_cfg_opts, "") == STS_FAILURE) {
       exit(1);
@@ -237,6 +235,13 @@
    configuration.configfile = strdup(configfile);
    configuration.config_search = config_search;
 
+   /* Don't log to stderr if daemonizing is intended. */
+   if (configuration.daemonize) {
+     log_set_stderr(0);
+   }
+
+   INFO(PACKAGE"-"VERSION"-"BUILDSTR" "UNAME" starting up");
+
    /* if a debug level > 0 has been given on the commandline use its
       value and not what is in the config file */
    if (cmdline_debuglevel != 0) {
@@ -301,7 +306,7 @@
     * the jail, too. However, it will be owned by root and not deleted
     * on process termination... */
    if (configuration.chrootjail && ((getuid()==0) || (geteuid()==0))) {
-      if (pidfilename) createpidfile(pidfilename);
+      if (pidfilename && *pidfilename == '/') createpidfile(pidfilename);
    }
 
    /* change user and group IDs */
