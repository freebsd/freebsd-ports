--- src/main/version.c.orig	2014-11-18 19:56:52 UTC
+++ src/main/version.c
@@ -66,8 +66,7 @@ int ssl_check_version(int allow_vulnerab
 	mismatch:
 		radlog(L_ERR, "libssl version mismatch.  built: %lx linked: %lx",
 		       (unsigned long) ssl_built, (unsigned long) ssl_linked);
-
-		return -1;
+		return 0;
 	}
 
 	/*
@@ -84,18 +83,6 @@ int ssl_check_version(int allow_vulnerab
 	 */
 	} else if ((ssl_built & 0xffffff) != (ssl_linked & 0xffffff)) goto mismatch;
 
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
 
