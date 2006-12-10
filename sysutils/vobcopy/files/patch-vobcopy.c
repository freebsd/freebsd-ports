--- vobcopy.c.orig	Mon Dec  4 23:50:04 2006
+++ vobcopy.c	Mon Dec  4 23:52:23 2006
@@ -146,6 +146,8 @@
 #endif
   
   
+  /* initialize string */
+  dvd_path[0] = '\0';
 
   /*
    * the getopt part (getting the options from command line)
