--- libopendkim/dkim-canon.c.orig	2015-05-11 03:56:13 UTC
+++ libopendkim/dkim-canon.c
@@ -388,7 +388,7 @@ dkim_canon_header_string(struct dkim_dstring *dstr, dk
 		}
 
 		/* skip all spaces before first word */
-		while (*p != '\0' && DKIM_ISWSP(*p))
+		while (*p != '\0' && DKIM_ISLWSP(*p))
 			p++;
 
 		space = FALSE;				/* just saw a space */
