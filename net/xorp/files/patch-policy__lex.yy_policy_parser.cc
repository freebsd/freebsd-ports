--- policy/lex.yy_policy_parser.cc.orig	2012-01-11 17:56:10 UTC
+++ policy/lex.yy_policy_parser.cc
@@ -2982,6 +2982,7 @@ static void yy_flex_strncpy (char *,yyco
 static int yy_flex_strlen (yyconst char * );
 #endif
 
+#define YY_NO_INPUT
 #ifndef YY_NO_INPUT
 
 #ifdef __cplusplus
