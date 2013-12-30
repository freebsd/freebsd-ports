--- lib/cftoken.l-	2013-12-21 11:31:18.701191439 +0900
+++ lib/cftoken.l	2013-12-21 11:33:51.653300338 +0900
@@ -53,7 +53,7 @@
 extern int yyget_lineno (void);
 extern FILE *yyget_in (void);
 extern FILE *yyget_out (void);
-extern int yyget_leng (void);
+extern yy_size_t yyget_leng (void);
 extern char *yyget_text (void);
 extern void yyset_lineno (int);
 extern void yyset_in (FILE *);
@@ -78,7 +78,7 @@
 	if (cf_debug) { \
 		fprintf(CF_ERRDEV, "%s:%d:%d[%s] len=%d\n", \
 		    rcf_istk[rcf_istkp].path, rcf_istk[rcf_istkp].lineno, \
-		    yy_start, yytext, yyleng); \
+		    yy_start, yytext, (int)yyleng); \
 	}
 #else
 #define DP
