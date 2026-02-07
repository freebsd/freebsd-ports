--- src/main/version.c.orig	2014-12-17 21:49:16 UTC
+++ src/main/version.c
@@ -61,8 +61,7 @@ int ssl_check_consistency(void)
 		ERROR("libssl version mismatch.  built: %lx linked: %lx",
 		      (unsigned long) ssl_built,
 		      (unsigned long) ssl_linked);
-
-		return -1;
+		return 0;
 	}
 
 	/*
