--- ./policy/lex.yy_policy_parser.cc.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./policy/lex.yy_policy_parser.cc	2014-02-26 21:17:13.000000000 +0000
@@ -2982,6 +2982,7 @@
 static int yy_flex_strlen (yyconst char * );
 #endif
 
+#define YY_NO_INPUT
 #ifndef YY_NO_INPUT
 
 #ifdef __cplusplus
