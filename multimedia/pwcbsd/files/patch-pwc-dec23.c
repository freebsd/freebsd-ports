--- pwc-dec23.c.orig	2013-09-05 17:36:27.000000000 +0200
+++ pwc-dec23.c	2013-09-05 17:37:27.000000000 +0200
@@ -261,7 +261,7 @@
 {
 	int flags;
 	struct pwc_dec23_private *pdev = data;
-	release = release;
+	/* release = release; */
 
 	switch (type) {
 	case 720:
