--- dd_rescue.c.orig	Mon Feb 14 09:47:10 2005
+++ dd_rescue.c	Tue Mar 15 00:59:42 2005
@@ -717,7 +717,8 @@
 		ipos = 0;
 
 #ifdef O_DIRECT
-	if (posix_memalign(mp, sysconf(_SC_PAGESIZE), softbs)) {
+	buf = malloc(softbs);
+	if (!buf) {
 		fplog(stderr, "dd_rescue: (fatal): allocation of aligned buffer failed!\n");
 		cleanup(); exit(18);
 	}
