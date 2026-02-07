--- src/posixtm.y.orig	2000-07-22 06:13:16 UTC
+++ src/posixtm.y
@@ -40,6 +40,11 @@ char *alloca ();
 #include <time.h>
 
 #define YYDEBUG 1
+#define yychar yychar_posixtm
+#define yyerrflag yyerrflag_posixtm
+#define yylval yylval_posixtm
+#define yynerrs yynerrs_posixtm
+#define yyval yyval_posixtm
 
 /* Lexical analyzer's current scan position in the input string. */
 static char *curpos;
@@ -85,6 +90,7 @@ date :
 		   YYABORT;
 		 }
 	       }
+	   ;
 
 year : digitpair {
                    t.tm_year = $1;
