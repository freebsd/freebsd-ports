--- a2kfcnv.c.orig	1998-12-21 23:51:14 UTC
+++ a2kfcnv.c
@@ -46,14 +46,13 @@ unsigned char font[256][MAXHEIGHT];
 
 #include "koi82alt.h"
 
-logo()
+static void logo(void)
 {
 	fprintf(stderr, "Freeware a2kfcnv v1.1\n\
 Copyright (C) 1993-1994 by Andrew A. Chernov, Moscow, Russia\n");
 }
 
-main(ac, av)
-char *av[];
+int main(int ac, char *av[])
 {
 	register i, j, n;
 	FILE *af, *kf;
@@ -121,7 +120,7 @@ usage:
 	}
 	size /= 256;
 	if (size > MAXHEIGHT) {
-		fprintf(stderr, "%s: %ld - font height too big, maximum %ld\n",
+		fprintf(stderr, "%s: %ld - font height too big, maximum %d\n",
 				av[1], size, MAXHEIGHT);
 		return 1;
 	}
