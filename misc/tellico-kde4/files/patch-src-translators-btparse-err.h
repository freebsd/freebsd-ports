--- src/translators/btparse/err.h.orig	Sun Aug 15 18:48:06 2004
+++ src/translators/btparse/err.h	Sun Aug 15 18:50:09 2004
@@ -118,7 +118,6 @@
 	int *err_k;
 	int i;
 	va_list ap;
-	int k;
 	va_start(ap, k);
 	text[0] = '\0';
 	for (i=1; i<=k; i++)	/* collect all lookahead sets */
