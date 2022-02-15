--- src/parsessh.y.orig	1999-12-16 01:06:30 UTC
+++ src/parsessh.y
@@ -740,7 +740,7 @@ exception_def_opt:
 void
 yyerror (const char *msg)
 {
-  error_at_line (1, 0, sshfilename, sshlineno, msg);
+  error_at_line (1, 0, sshfilename, sshlineno, "%s", msg);
 }
 
 /*
