--- spell/spellin.c.orig	Fri Feb  3 19:13:19 2006
+++ spell/spellin.c	Fri Feb  3 19:19:20 2006
@@ -77,6 +77,7 @@
 main(int argc, char **argv)
 {
 	int32_t h, k, d;
+	unsigned hu;
 	int32_t  i;
 	int32_t count;
 	int32_t w1;
@@ -103,7 +104,8 @@
 	z = huff((1L<<HASHWIDTH)/atof(argv[1]));
 	fprintf(stderr, "%s: expected code widths = %f\n",
 	    argv[0], z);
-	for (count = 0; scanf("%lo", (long *)&h) == 1; ++count) {
+	for (count = 0; scanf("%o", &hu) == 1; ++count) {
+		h = (int32_t)hu;
 		if ((t = h >> (HASHWIDTH - INDEXWIDTH)) != u) {
 			if (bp != B)
 				wp++;
