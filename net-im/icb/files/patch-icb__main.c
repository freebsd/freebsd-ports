--- icb/main.c.orig	2000-12-12 16:02:07.000000000 +0900
+++ icb/main.c	2012-10-25 18:18:39.000000000 +0900
@@ -279,7 +279,7 @@
 #endif
 		readlineinit();
 		if (restrictflg && !gv.restricted)
-			restrict(); 
+			icb_restrict(); 
 	}
 
 	/* try to connect to port - if it fails, start server if we are on */
