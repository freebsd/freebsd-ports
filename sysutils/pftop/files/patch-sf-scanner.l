--- sf-scanner.l.orig	2007-11-07 07:34:18.000000000 +0100
+++ sf-scanner.l	2008-04-01 17:03:25.853268641 +0200
@@ -233,7 +233,7 @@
 			size_t len = strlen(yytext) * 4 + 1;
 			char *v = malloc(len);
 			if (v != NULL)
-				strnvis(v, yytext, len, 0);
+				strvis(v, yytext, 0);
 			sf_error("illegal token: %s", v);
 			free(v);
 			}
