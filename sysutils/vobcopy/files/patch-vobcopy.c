--- vobcopy.c.orig	Fri Jan  6 23:49:40 2006
+++ vobcopy.c	Fri Jan  6 23:50:03 2006
@@ -146,6 +146,8 @@
 #endif
   
   
+  /* initialize string */
+  dvd_path[0] = '\0';
 
   /*
    * the getopt part (getting the options from command line)
