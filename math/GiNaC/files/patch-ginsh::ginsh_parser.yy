--- ginsh/ginsh_parser.yy.orig	Wed Feb 28 20:55:04 2001
+++ ginsh/ginsh_parser.yy	Tue Mar  6 16:45:06 2001
@@ -29,6 +29,7 @@
 %{
 #include "config.h"
 
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #if HAVE_UNISTD_H
@@ -720,6 +721,8 @@
 /*
  *  Main program
  */
+
+int yyparse();
 
 int main(int argc, char **argv)
 {
