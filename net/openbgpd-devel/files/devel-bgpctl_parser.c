--- bgpctl/parser.c.orig	Mon Mar 20 11:57:05 2006
+++ bgpctl/parser.c	Mon Mar 20 11:57:27 2006
@@ -29,6 +29,9 @@
 
 #include "parser.h"
 
+/* Ok, this is awful. */
+#include "strtonum.c"
+
 enum token_type {
 	NOTOKEN,
 	ENDTOKEN,
