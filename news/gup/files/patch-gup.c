--- gup.c.orig	Sun Oct 20 16:55:33 2002
+++ gup.c	Sun Oct 20 16:55:50 2002
@@ -37,7 +37,7 @@
 
 
 char	*progname = "gup";		/* GC */
-FILE	*log_fp = stderr;
+FILE	*log_fp;
 
 static	char	*usage =
 "\n\
@@ -165,6 +165,8 @@
 
     int		changed;
 
+    log_fp = stderr;
+ 
     umask(UMASK);
 
     parse_options(argc, argv);		/* Decode our command line options */
