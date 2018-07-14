--- rtrmgr/y.boot_tab.cc.orig	2018-07-12 14:14:48 UTC
+++ rtrmgr/y.boot_tab.cc
@@ -474,9 +474,9 @@ int
 yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
 {
-    register int yym, yyn, yystate;
+    int yym, yyn, yystate;
 #if YYDEBUG
-    register const char *yys;
+    const char *yys;
 
     if ((yys = getenv("YYDEBUG")))
     {
