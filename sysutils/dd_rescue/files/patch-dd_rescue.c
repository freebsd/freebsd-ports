--- dd_rescue.c.orig	Sun Jul 23 20:47:50 2006
+++ dd_rescue.c	Mon Feb 12 02:53:35 2007
@@ -213,11 +213,13 @@
 
 void savebb( int block )
 {
+	FILE *bbfile;
+
 	fplog(stderr, "Bad block: %d\n", block);
     
 	if( bbname == NULL )
 		return;
-	FILE *bbfile = fopen(bbname,"a");
+	bbfile = fopen(bbname,"a");
 	fprintf(bbfile,"%d\n",block);
 	fclose(bbfile);
 }
@@ -742,7 +744,8 @@
 		ipos = 0;
 
 #ifdef O_DIRECT
-	if (posix_memalign(mp, sysconf(_SC_PAGESIZE), softbs)) {
+	buf = malloc(softbs);
+	if (!buf) {
 		fplog(stderr, "dd_rescue: (fatal): allocation of aligned buffer failed!\n");
 		cleanup(); exit(18);
 	}
