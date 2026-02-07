--- grammar.y.orig	2008-01-18 17:43:20 UTC
+++ grammar.y
@@ -70,10 +70,12 @@
 static struct qual qerr = { Q_UNDEF, Q_UNDEF, Q_UNDEF, Q_UNDEF };
 #endif
 
+extern int yylex (void);
+
 int n_errors = 0;
 struct ctrl *root;
 char *yyfilename;
-int yylineno;
+extern int yylineno;
 
 #ifdef HAVE_STDARG_H
 /* GCC complains if we declare this function in traditional style */
