--- ginsh/ginsh_parser.yy.orig	Tue Oct 15 17:15:25 2002
+++ ginsh/ginsh_parser.yy	Tue Oct 15 17:18:14 2002
@@ -29,6 +29,7 @@
 %{
 #include "config.h"
 
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #if HAVE_UNISTD_H
@@ -796,6 +797,8 @@
 /*
  *  Main program
  */
+
+int yyparse();
 
 int main(int argc, char **argv)
 {
