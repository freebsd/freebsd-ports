--- ./modules/ssl/ssl_expr_eval.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/ssl/ssl_expr_eval.c	2010-10-21 05:40:53.660623887 +0000
@@ -126,24 +126,24 @@
             ssl_expr *e1;
             ssl_expr *e2;
             char *word;
-            regex_t *regex;
+            ap_regex_t *regex;
 
             e1 = (ssl_expr *)node->node_arg1;
             e2 = (ssl_expr *)node->node_arg2;
             word = ssl_expr_eval_word(r, e1);
-            regex = (regex_t *)(e2->node_arg1);
+            regex = (ap_regex_t *)(e2->node_arg1);
             return (ap_regexec(regex, word, 0, NULL, 0) == 0);
         }
         case op_NRE: {
             ssl_expr *e1;
             ssl_expr *e2;
             char *word;
-            regex_t *regex;
+            ap_regex_t *regex;
 
             e1 = (ssl_expr *)node->node_arg1;
             e2 = (ssl_expr *)node->node_arg2;
             word = ssl_expr_eval_word(r, e1);
-            regex = (regex_t *)(e2->node_arg1);
+            regex = (ap_regex_t *)(e2->node_arg1);
             return !(ap_regexec(regex, word, 0, NULL, 0) == 0);
         }
         default: {
