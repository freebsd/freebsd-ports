--- src/lib/util/keyval/ipv2_scan.cc.orig	2018-07-22 01:07:05 UTC
+++ src/lib/util/keyval/ipv2_scan.cc
@@ -673,7 +673,7 @@ YY_RULE_SETUP
                     }
                   yylval.str = (char *)malloc(strlenyytext+1);
                   if (!yylval.str) {
-                    ExEnv::errn() << "IPV2: {string} rule: malloc failed" << endl;
+                    ExEnv::errn() << "IPV2: {string} rule: malloc failed" << std::endl;
                     abort();
                     }
                   strcpy(yylval.str,yytext);
@@ -684,7 +684,7 @@ case 3:
 YY_RULE_SETUP
 { yylval.str = (char *)malloc(strlen(yytext));
                   if (!yylval.str) {
-                    ExEnv::errn() << "IPV2: {qstring} rule: malloc failed" << endl;
+                    ExEnv::errn() << "IPV2: {qstring} rule: malloc failed" << std::endl;
                     abort();
                     }
                   strcpy(yylval.str,&yytext[1]);
