--- src/libmy/strb64d.c.orig	2013-09-10 09:58:37.814139989 +0200
+++ src/libmy/strb64d.c	2013-09-10 10:00:47.489957357 +0200
@@ -47,14 +47,14 @@
 int
 strb64d(char *dst, const char *src, const int dsize)
 {
-	int		ch, i, j = 0;
+	int		ch, i, j;
 	char		out[3];
 	unsigned char	in_a[4], in_b[4];
 
 	dst[0] = '\0';
 
 	while (1) {
-		for (i = 0, j = j; i < 4; i++, j++) {
+		for (i = 0, j = 0; i < 4; i++, j++) {
 			if (src[j] == '\0')
 				goto quit;
 			ch = src[j];
