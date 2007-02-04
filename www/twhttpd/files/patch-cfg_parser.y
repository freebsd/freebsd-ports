--- cfg_parser.y.orig	Sat Aug 31 11:41:16 2002
+++ cfg_parser.y	Sun Feb  4 20:06:36 2007
@@ -27,10 +27,12 @@
 #include       <regex.h>
 #include       <errno.h>
 #include       <stdio.h>
-#include       <arpa/inet.h>
+#include       <stdlib.h>
+#include       <string.h>
 #include       <sys/types.h>
 #include       <sys/socket.h>
 #include       <netinet/in.h>
+#include       <arpa/inet.h>
 
 #include       "config.h"
 #include       "cfg_functions.h"
@@ -467,8 +469,8 @@
                         $$ = (decision_tree *)cf_malloc(sizeof(decision_tree));
                         init_dt($$);
                         $$->f = &cfg_numeric_test;
-                        (cfg_variable *)$$->value = $1;
-                        (int *)$$->value2 = (int *)cf_malloc(sizeof(int));
+                        $$->value = $1;
+                        $$->value2 = cf_malloc(sizeof(int));
                         *(int *)$$->value2 = $3;
                         $$->property = $2;
                     }
@@ -563,7 +565,7 @@
                         $$ = (decision_tree *)cf_malloc(sizeof(decision_tree));
                         init_dt($$);
                         $$->f = &cfg_set_location;
-                        (char *)$$->value = strdup($3);
+                        $$->value = strdup($3);
                     }
     ;
 
@@ -623,19 +625,19 @@
 
 num_var:            PORT
                     {
-                        (cfg_variable *)$$ = (cfg_variable *)cf_malloc(sizeof(cfg_variable));
+                        $$ = (cfg_variable *)cf_malloc(sizeof(cfg_variable));
                         $$->type = PORT;
                         $$->f = NULL;
                     }
     |               POST_LEN
                     {
-                        (cfg_variable *)$$ = (cfg_variable *)cf_malloc(sizeof(cfg_variable));
+                        $$ = (cfg_variable *)cf_malloc(sizeof(cfg_variable));
                         $$->type = POST_LEN;
                         $$->f = NULL;
                     }
     |               STRLEN '(' str_var ')'
                     {
-                        (cfg_variable *)$$ = (cfg_variable *)cf_malloc(sizeof(cfg_variable));
+                        $$ = (cfg_variable *)cf_malloc(sizeof(cfg_variable));
                         $$->type = $3;
                         $$->f = &cfg_strlen;
                     }
