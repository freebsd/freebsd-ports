--- libscg/scsitransp.c.orig	Fri Apr 20 10:38:05 2001
+++ libscg/scsitransp.c	Wed May 28 19:36:31 2003
@@ -1016,7 +1016,7 @@
 	register Uchar	*cp;
 	register int	n;
 {
-	js_fprintf(f, s);
+	js_fprintf(f, "%s", s);
 	while (--n >= 0)
 		js_fprintf(f, " %02X", *cp++);
 	js_fprintf(f, "\n");
