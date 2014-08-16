--- ./src/main/version.c.orig	2014-08-16 16:17:41.000000000 -0400
+++ ./src/main/version.c	2014-08-16 16:18:31.000000000 -0400
@@ -60,21 +60,8 @@
 		       (unsigned long) ssl_built,
 		       (unsigned long) ssl_linked);
 
-		return -1;
 	};
 
-	if (!allow_vulnerable) {
-		/* Check for bad versions */
-		/* 1.0.1 - 1.0.1f CVE-2014-0160 http://heartbleed.com */
-		if ((ssl_linked >= 0x010001000) && (ssl_linked < 0x010001070)) {
-			radlog(L_ERR, "Refusing to start with libssl version %s (in range 1.0.1 - 1.0.1f).  "
-			      "Security advisory CVE-2014-0160 (Heartbleed)", ssl_version());
-			radlog(L_ERR, "For more information see http://heartbleed.com");
-
-			return -1;
-		}
-	}
-
 	return 0;
 }
 
