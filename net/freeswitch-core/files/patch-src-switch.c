--- src/switch.c.orig	2010-05-11 23:58:27.000000000 -0700
+++ src/switch.c	2010-05-12 00:19:56.000000000 -0700
@@ -661,11 +661,6 @@
 		return 255;
 	}
 
-	if (alt_dirs && alt_dirs != 3) {
-		fprintf(stderr, "You must specify all or none of -conf, -log, and -db\n");
-		return 255;
-	}
-
 	signal(SIGILL, handle_SIGILL);
 	signal(SIGTERM, handle_SIGILL);
 
