--- lib/cftoken.l.orig	2018-08-15 21:36:53.000000000 -0700
+++ lib/cftoken.l	2018-10-19 12:15:39.256861000 -0700
@@ -81,7 +81,7 @@
 	if (cf_debug) { \
 		fprintf(CF_ERRDEV, "%s:%d:%d[%s] len=%zu\n", \
 		    rcf_istk[rcf_istkp].path, rcf_istk[rcf_istkp].lineno, \
-		    yy_start, yytext, yyleng); \
+		    yy_start, yytext, (int)yyleng); \
 	}
 #else
 #define DP
