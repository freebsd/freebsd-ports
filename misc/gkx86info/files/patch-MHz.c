--- MHz.c.orig	Sat Oct  6 05:41:06 2001
+++ MHz.c	Wed Aug  7 23:01:05 2002
@@ -11,6 +11,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/time.h>
 #include <string.h>
 #include <unistd.h>
@@ -45,7 +46,7 @@
 	microseconds = ((tvstop.tv_sec-tvstart.tv_sec)*1000000) +
 		(tvstop.tv_usec-tvstart.tv_usec);
 
-	buffer = malloc(sizeof(char)*512);
+	buffer = (char *) malloc(sizeof(char)*512);
 	sprintf(buffer, "%lldMHz",
 		(cycles[1]-cycles[0])/microseconds);
 
