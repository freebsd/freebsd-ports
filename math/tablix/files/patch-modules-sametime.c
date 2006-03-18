--- modules/sametime.c.orig	Sat Feb 18 11:58:36 2006
+++ modules/sametime.c	Sat Feb 18 11:59:38 2006
@@ -90,9 +90,9 @@
 	resource *res2;
 	resourcetype *restype;
 
-	restype=res1->restype;
-
 	int n;
+
+	restype=res1->restype;
 
 	res2=res_find(restype, cont);
 
