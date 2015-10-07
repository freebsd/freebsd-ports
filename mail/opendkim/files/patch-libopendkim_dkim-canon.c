--- libopendkim/dkim-canon.c.orig	2015-08-26 08:37:01 UTC
+++ libopendkim/dkim-canon.c
@@ -388,7 +388,7 @@ dkim_canon_header_string(struct dkim_dst
 		}
 
 		/* skip all spaces before first word */
-		while (*p != '\0' && DKIM_ISWSP(*p))
+		while (*p != '\0' && DKIM_ISLWSP(*p))
 			p++;
 
 		space = FALSE;				/* just saw a space */
