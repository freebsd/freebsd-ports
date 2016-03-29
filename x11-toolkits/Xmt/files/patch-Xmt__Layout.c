--- Xmt/Layout.c.orig	2001-07-06 18:38:33.000000000 -0700
+++ Xmt/Layout.c	2016-03-26 11:28:48.423314000 -0700
@@ -1497,7 +1497,7 @@
     Dimension width, height, border_width;
 
     if (XtIsShell(w)) {
-	return;
+	return(0);
     }
 
     /* this is case 2 described above */
