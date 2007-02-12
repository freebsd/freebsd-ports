--- gmime/gmime-utils.c.orig	Mon Feb 12 10:53:03 2007
+++ gmime/gmime-utils.c	Mon Feb 12 10:53:21 2007
@@ -646,7 +646,7 @@
 					goto next;
 				} else if (!tm.tm_year) {
 					if ((n = get_year (token->start, token->len)) != -1) {
-						printf ("2-digit year; ");
+						d(printf ("2-digit year; "));
 						tm.tm_year = n - 1900;
 					}
 					goto next;
