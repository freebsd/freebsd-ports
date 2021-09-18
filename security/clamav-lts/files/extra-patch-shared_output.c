--- shared/output.c.orig	Thu May 18 22:10:40 2006
+++ shared/output.c	Thu May 18 22:12:43 2006
@@ -236,7 +236,13 @@
 	return;
     }
 
-    fd = stdout;
+/*    fd = stdout; (missing flag 'mprintf_stdout') --eh.  */
+
+     if(mprintf_stdout)
+         fd = stdout;
+     else
+         fd = stderr;
+
 
 /* legend:
  * ! - error
