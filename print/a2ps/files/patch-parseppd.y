--- lib/parseppd.y.orig	1999-12-16 01:00:13 UTC
+++ lib/parseppd.y
@@ -154,7 +154,7 @@ font_clause :
 void
 yyerror (const char *msg)
 {
-  error_at_line (1, 0, ppdfilename, ppdlineno, msg);
+  error_at_line (1, 0, ppdfilename, ppdlineno, "%s", msg);
 }
 
 /*
