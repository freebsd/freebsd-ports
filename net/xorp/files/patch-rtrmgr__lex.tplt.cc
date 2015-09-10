--- rtrmgr/lex.tplt.cc.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/lex.tplt.cc
@@ -8667,6 +8667,7 @@ static void yy_flex_strncpy YY_PROTO(( c
 static int yy_flex_strlen YY_PROTO(( yyconst char * ));
 #endif
 
+#define YY_NO_INPUT
 #ifndef YY_NO_INPUT
 #ifdef __cplusplus
 static int yyinput YY_PROTO(( void ));
@@ -9708,6 +9709,7 @@ register char *yy_bp;
 #endif	/* ifndef YY_NO_UNPUT */
 
 
+#ifndef YY_NO_INPUT
 #ifdef __cplusplus
 static int yyinput()
 #else
@@ -9779,7 +9781,7 @@ static int input()
 
 	return c;
 	}
-
+#endif
 
 #ifdef YY_USE_PROTOS
 void yyrestart( FILE *input_file )
