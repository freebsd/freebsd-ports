--- src/lib/util/keyval/ipv2_scan.ll.orig	2018-07-22 01:07:58 UTC
+++ src/lib/util/keyval/ipv2_scan.ll
@@ -59,7 +59,7 @@ qstring \"[^"\n]+\"
                     }
                   yylval.str = (char *)malloc(strlenyytext+1);
                   if (!yylval.str) {
-                    ExEnv::errn() << "IPV2: {string} rule: malloc failed" << endl;
+                    ExEnv::errn() << "IPV2: {string} rule: malloc failed" << std::endl;
                     abort();
                     }
                   strcpy(yylval.str,yytext);
@@ -67,7 +67,7 @@ qstring \"[^"\n]+\"
                   }
 {qstring}       { yylval.str = (char *)malloc(strlen(yytext));
                   if (!yylval.str) {
-                    ExEnv::errn() << "IPV2: {qstring} rule: malloc failed" << endl;
+                    ExEnv::errn() << "IPV2: {qstring} rule: malloc failed" << std::endl;
                     abort();
                     }
                   strcpy(yylval.str,&yytext[1]);
