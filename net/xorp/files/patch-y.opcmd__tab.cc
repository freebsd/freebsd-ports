--- rtrmgr/y.opcmd_tab.cc.orig	2018-07-12 14:13:19 UTC
+++ rtrmgr/y.opcmd_tab.cc
@@ -684,9 +684,9 @@ int
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
