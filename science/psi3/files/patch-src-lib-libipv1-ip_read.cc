--- src/lib/libipv1/ip_read.cc.orig
+++ src/lib/libipv1/ip_read.cc
@@ -12,7 +12,9 @@
 #include "ip_types.h"
 #define _IP_ALLOCATE_GLOBAL_
 #include "ip_global.h"
+extern "C" {
 #include "y.tab.h"
+}
 
 #include "ip_read.gbl"
 #include "ip_read.lcl"
@@ -27,7 +29,6 @@
 
 /* The input for yacc. */
 extern FILE *yyin;
-extern void yyparse(void);
 
 /* Set up static variables. */
 /*static ip_keyword_tree_t *sub_tree = NULL;*/
