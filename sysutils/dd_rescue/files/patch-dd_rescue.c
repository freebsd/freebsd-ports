--- dd_rescue.c.orig	Sun Mar 18 07:29:10 2007
+++ dd_rescue.c
@@ -742,7 +742,8 @@
 		ipos = 0;
 
 #ifdef O_DIRECT
-	if (posix_memalign(mp, sysconf(_SC_PAGESIZE), softbs)) {
+	buf = malloc(softbs);
+	if (!buf) {
 		fplog(stderr, "dd_rescue: (fatal): allocation of aligned buffer failed!\n");
 		cleanup(); exit(18);
 	}
