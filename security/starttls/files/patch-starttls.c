--- starttls.c.orig	Fri Feb 13 23:30:28 2004
+++ starttls.c	Fri Feb 13 23:30:37 2004
@@ -229,7 +229,7 @@
 #else
   fd_set readfds, writefds;
 #endif
-  char buffer[BUFSIZ], *retry;
+  char buffer[BUFSIZ*8], *retry;
   struct sigaction act;
 
   int this_option_optind = optind ? optind : 1;
