--- wmqmon.c.orig	Fri Feb 23 04:57:29 2001
+++ wmqmon.c	Mon May 28 15:01:01 2001
@@ -33,13 +33,13 @@
 #define EMAIL "w1nter@gibfest.org"
 #define WEBPAGE "http://www.gibfest.org/~w1nter/"
 
-#include <sys/socket.h>
 #include <sys/time.h>
 #include <sys/timeb.h>
 #include <sys/poll.h>
 #include <sys/wait.h>
 #include <sys/param.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 
 #include <stdio.h>
 #include <stdlib.h>
