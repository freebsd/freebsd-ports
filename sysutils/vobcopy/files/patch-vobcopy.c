--- vobcopy.c.orig	Sun Jun 24 08:26:07 2007
+++ vobcopy.c	Wed Oct 10 20:56:58 2007
@@ -149,6 +149,8 @@
 #endif
 
 
+   /* initialize string */
+   dvd_path[0] = '\0';
 
   /*
    * the getopt part (getting the options from command line)
