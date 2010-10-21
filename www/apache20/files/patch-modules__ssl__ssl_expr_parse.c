--- ./modules/ssl/ssl_expr_parse.c.orig	2010-10-14 18:00:30.000000000 +0000
+++ ./modules/ssl/ssl_expr_parse.c	2010-10-21 05:40:53.661622060 +0000
@@ -818,9 +818,9 @@
 case 24:
 #line 148 "ssl_expr_parse.y"
 { 
-                regex_t *regex;
+                ap_regex_t *regex;
                 if ((regex = ap_pregcomp(ssl_expr_info.pool, ssl_expr_yyvsp[0].cpVal, 
-                                         REG_EXTENDED|REG_NOSUB)) == NULL) {
+                                         AP_REG_EXTENDED|AP_REG_NOSUB)) == NULL) {
                     ssl_expr_error = "Failed to compile regular expression";
                     YYERROR;
                     regex = NULL;
@@ -831,9 +831,9 @@
 case 25:
 #line 158 "ssl_expr_parse.y"
 {
-                regex_t *regex;
+                ap_regex_t *regex;
                 if ((regex = ap_pregcomp(ssl_expr_info.pool, ssl_expr_yyvsp[0].cpVal, 
-                                         REG_EXTENDED|REG_NOSUB|REG_ICASE)) == NULL) {
+                                         AP_REG_EXTENDED|AP_REG_NOSUB|AP_REG_ICASE)) == NULL) {
                     ssl_expr_error = "Failed to compile regular expression";
                     YYERROR;
                     regex = NULL;
