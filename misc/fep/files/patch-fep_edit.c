--- fep_edit.c.orig	Fri Jan 20 17:16:37 1995
+++ fep_edit.c	Thu Mar  6 09:42:13 2003
@@ -426,7 +426,7 @@
 
     currentNull = strlen (CommandLine);
 
-    if (currentNull >= maxline) {
+    if (currentNull + 1 >= maxline) {
         errorBell();
 	return (0);
     }
