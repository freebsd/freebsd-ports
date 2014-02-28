--- ./rtrmgr/lex.boot.cc.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./rtrmgr/lex.boot.cc	2014-02-26 21:17:13.000000000 +0000
@@ -9552,6 +9552,7 @@
 static int yy_flex_strlen YY_PROTO(( yyconst char * ));
 #endif
 
+#define YY_NO_INPUT
 #ifndef YY_NO_INPUT
 #ifdef __cplusplus
 static int yyinput YY_PROTO(( void ));
@@ -10483,6 +10484,7 @@
 #endif	/* ifndef YY_NO_UNPUT */
 
 
+#ifndef YY_NO_INPUT
 #ifdef __cplusplus
 static int yyinput()
 #else
@@ -10554,7 +10556,7 @@
 
 	return c;
 	}
-
+#endif
 
 #ifdef YY_USE_PROTOS
 void yyrestart( FILE *input_file )
