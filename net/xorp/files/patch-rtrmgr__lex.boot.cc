--- rtrmgr/lex.boot.cc.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/lex.boot.cc
@@ -9552,6 +9552,7 @@ static void yy_flex_strncpy YY_PROTO(( c
 static int yy_flex_strlen YY_PROTO(( yyconst char * ));
 #endif
 
+#define YY_NO_INPUT
 #ifndef YY_NO_INPUT
 #ifdef __cplusplus
 static int yyinput YY_PROTO(( void ));
@@ -10483,6 +10484,7 @@ register char *yy_bp;
 #endif	/* ifndef YY_NO_UNPUT */
 
 
+#ifndef YY_NO_INPUT
 #ifdef __cplusplus
 static int yyinput()
 #else
@@ -10554,7 +10556,7 @@ static int input()
 
 	return c;
 	}
-
+#endif
 
 #ifdef YY_USE_PROTOS
 void yyrestart( FILE *input_file )
