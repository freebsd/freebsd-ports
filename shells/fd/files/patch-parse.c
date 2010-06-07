Patch by Rikito INAKAZU [FDclone-users:00861]

diff -u parse.c.orig parse.c
--- parse.c.orig	2010-06-04 00:00:00.000000000 +0900
+++ parse.c	2010-06-05 22:16:04.000000000 +0900
@@ -831,7 +831,7 @@
 		while (*cp) {
 			*bufp = c_realloc(*bufp, j + MAXCHARWID - 1, &size);
 			if (unprint) {
-				(*bufp)[j] = *cp;
+				(*bufp)[j++] = *cp++;
 				continue;
 			}
 
