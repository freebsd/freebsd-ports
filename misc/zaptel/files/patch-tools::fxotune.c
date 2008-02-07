--- tools/fxotune.c.orig	Thu Jan  4 02:13:23 2007
+++ tools/fxotune.c	Wed Feb  6 11:43:10 2008
@@ -320,7 +320,7 @@
 			mycoefs.coef7 = mycoef7;
 			mycoefs.coef8 = mycoef8;
 		
-			snprintf(completezappath, sizeof(completezappath), "%s/%d", zappath, myzap);
+			snprintf(completezappath, sizeof(completezappath), "%s/channel%d", zappath, myzap);
 			fd = open(completezappath, O_RDWR);
 
 			if (fd < 0) {
@@ -356,7 +356,7 @@
 		}
 
 		for (i = 0; i < 252; i++) {
-			snprintf(zapdev, sizeof(zapdev), "%s/%d", zappath, i+1);
+			snprintf(zapdev, sizeof(zapdev), "%s/channel%d", zappath, i+1);
 
 			fd = open(zapdev, O_RDWR);
 			if (fd < 0) {
