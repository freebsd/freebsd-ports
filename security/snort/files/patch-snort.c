--- src/snort.c.orig	Fri Mar 14 19:58:33 2003
+++ src/snort.c	Fri Mar 14 19:58:19 2003
@@ -1,4 +1,4 @@
-/* $Id: snort.c,v 1.157.2.7 2003/02/19 21:16:50 chris_reid Exp $ */
+/* $Id: snort.c,v 1.157.2.9 2003/03/04 20:47:15 andrewbaker Exp $ */
 /*
 ** Copyright (C) 1998-2002 Martin Roesch <roesch@sourcefire.com>
 **
@@ -252,6 +252,8 @@
         OpenPcap(pv.readfile, 0);
     }
 
+    InitOutputPlugins();
+    
     /* didn't get any conf data at the command line, try to find the default
      * conf file
      */ 
@@ -310,9 +312,6 @@
         GoDaemon();
     }
 
-    /* initialize these here so we do not print unwanted messages */
-    InitOutputPlugins();
-    
     /*
      * creating a PID file before setting its proper
      * path (in SanityChecks()) is not a good idea
@@ -2212,7 +2211,7 @@
     struct stat st;
     int found;
     int i;
-    char *conf_files[]={"/etc/snort.conf", "./snort.conf", NULL};
+    char *conf_files[]={"/usr/local/etc/snort.conf", "./snort.conf", NULL};
     char *fname = NULL;
     char *home_dir;
     char *tmp;
