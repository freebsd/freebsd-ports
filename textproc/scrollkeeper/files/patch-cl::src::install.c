--- cl/src/install.c.orig	Thu Mar 15 05:10:33 2001
+++ cl/src/install.c	Tue Apr  3 20:41:52 2001
@@ -499,3 +499,4 @@
     
-    dir = opendir(data_dir);
+    if ((dir = opendir(data_dir)) == NULL)
+	return;
     
