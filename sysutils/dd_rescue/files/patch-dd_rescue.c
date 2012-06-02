--- dd_rescue.c.orig	2012-05-20 05:46:14.000000000 +0900
+++ dd_rescue.c	2012-06-02 22:24:44.000000000 +0900
@@ -1194,11 +1194,11 @@
 		ipos = 0;
 
 #ifdef O_DIRECT
-	if (posix_memalign(&mp, pagesize, softbs)) {
+	buf = malloc(softbs);
+	if (!buf) {
 		fplog(stderr, "dd_rescue: (fatal): allocation of aligned buffer failed!\n");
 		cleanup(); exit(18);
 	}
-	buf = mp;
 #else
 	buf = malloc(softbs);
 	if (!buf) {
