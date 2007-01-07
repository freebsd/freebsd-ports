--- edit.c.orig	Thu May 13 19:04:33 1999
+++ edit.c	Sun Jan  7 22:48:23 2007
@@ -344,6 +344,7 @@
      */
     if (*cp && cp[1] == '\r') {
 	delimiter = *cp;
+	indelimit = !indelimit;
 	cp += 2;
     }
 
