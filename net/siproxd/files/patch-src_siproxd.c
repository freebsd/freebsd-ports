--- src/siproxd.c.orig	Thu Aug 26 19:32:08 2004
+++ src/siproxd.c	Thu Oct 14 07:18:15 2004
@@ -179,6 +179,7 @@
 /*
  * Init stuff
  */
+   INFO(PACKAGE"-"VERSION"-"BUILDSTR" started");
 
    /* read the config file */
    if (read_config(configfile, config_search) == STS_FAILURE) exit(1);
@@ -245,7 +246,6 @@
    /* initialize the registration facility */
    register_init();
 
-   INFO(PACKAGE"-"VERSION"-"BUILDSTR" started");
 /*
  * silence the log - if so required...
  */
