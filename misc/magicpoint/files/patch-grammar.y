--- grammar.y.orig	2008-01-18 17:43:20 UTC
+++ grammar.y
@@ -70,6 +70,8 @@
 static struct qual qerr = { Q_UNDEF, Q_UNDEF, Q_UNDEF, Q_UNDEF };
 #endif
 
+extern int yylex (void);
+
 int n_errors = 0;
 struct ctrl *root;
 char *yyfilename;
