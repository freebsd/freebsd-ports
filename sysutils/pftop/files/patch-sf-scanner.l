--- sf-scanner.l.orig	2022-06-07 16:20:35 UTC
+++ sf-scanner.l
@@ -233,7 +233,7 @@ rnr|rulenum	return RNR;
 			size_t len = strlen(yytext) * 4 + 1;
 			char *v = malloc(len);
 			if (v != NULL)
-				strnvis(v, yytext, len, 0);
+				strvis(v, yytext, 0);
 			sf_error("illegal token: %s", v);
 			free(v);
 			}
