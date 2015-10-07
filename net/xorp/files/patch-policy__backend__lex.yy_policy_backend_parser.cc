--- policy/backend/lex.yy_policy_backend_parser.cc.orig	2012-01-11 17:56:10 UTC
+++ policy/backend/lex.yy_policy_backend_parser.cc
@@ -617,6 +617,8 @@ static void yy_flex_strncpy (char *,yyco
 static int yy_flex_strlen (yyconst char * );
 #endif
 
+#define YY_NO_INPUT
+
 #ifndef YY_NO_INPUT
 
 #ifdef __cplusplus
