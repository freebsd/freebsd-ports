--- server/xover.c.orig	Tue Nov  1 07:09:24 1994
+++ server/xover.c	Mon Nov  4 05:50:22 2002
@@ -213,7 +213,9 @@
 		} while (c != EOF && c != '\n' && c != '\t');
 		printf("\r\n");
 	} else {
+#ifndef __FreeBSD__
 		char		*malloc(), *realloc();
+#endif
 		register int	size = 1024;
 		buf = malloc(size);
 		if (buf) {
@@ -248,7 +250,9 @@
 	register char	*cp, *cp2;
 	register int	hdr;
 	char		*array[OVER_FIELD_COUNT];
+#ifndef __FreeBSD__
 	char		*malloc(), *realloc();
+#endif
 
 	(void) sprintf(line, "%d", artnum);
 	fp = fopen(line, "r");
@@ -359,7 +363,9 @@
 	register FILE	*fp;
 	register char	*cp, *cp2;
 	char		*references = NULL;
+#ifndef __FreeBSD__
 	char		*malloc(), *realloc();
+#endif
 
 #ifdef XOVER
 	if (over_is_cheap(artnum, artnum)) {
