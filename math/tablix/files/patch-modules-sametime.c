--- modules/sametime.c.orig	Sun Sep  4 21:20:52 2005
+++ modules/sametime.c	Tue Nov 22 21:40:47 2005
@@ -64,9 +64,9 @@
 	resource *res2;
 	resourcetype *restype;
 
-	restype=res1->restype;
-
 	int n;
+
+	restype=res1->restype;
 
 	res2=res_find(restype, cont);
 
