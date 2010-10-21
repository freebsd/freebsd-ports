--- ./modules/ssl/ssl_expr_parse.y.orig	2010-10-14 18:00:24.000000000 +0000
+++ ./modules/ssl/ssl_expr_parse.y	2010-10-21 05:40:53.662624424 +0000
@@ -113,18 +113,18 @@
           ;
 
 regex     : T_REGEX { 
-                regex_t *regex;
+                ap_regex_t *regex;
                 if ((regex = ap_pregcomp(ssl_expr_info.pool, $1, 
-                                         REG_EXTENDED|REG_NOSUB)) == NULL) {
+                                         AP_REG_EXTENDED|AP_REG_NOSUB)) == NULL) {
                     ssl_expr_error = "Failed to compile regular expression";
                     YYERROR;
                 }
                 $$ = ssl_expr_make(op_Regex, regex, NULL);
             }
           | T_REGEX_I {
-                regex_t *regex;
+                ap_regex_t *regex;
                 if ((regex = ap_pregcomp(ssl_expr_info.pool, $1, 
-                                         REG_EXTENDED|REG_NOSUB|REG_ICASE)) == NULL) {
+                                         AP_REG_EXTENDED|AP_REG_NOSUB|AP_REG_ICASE)) == NULL) {
                     ssl_expr_error = "Failed to compile regular expression";
                     YYERROR;
                 }
