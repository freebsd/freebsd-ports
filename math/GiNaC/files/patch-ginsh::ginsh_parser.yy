--- ginsh/ginsh_parser.yy.orig	Sat Aug  5 22:36:18 2006
+++ ginsh/ginsh_parser.yy	Fri Oct  6 21:54:20 2006
@@ -28,6 +28,8 @@
 
 %{
 #include "config.h"
+#include <sys/time.h>
+
 #ifdef HAVE_RUSAGE
 #include <sys/resource.h>
 #else
@@ -888,6 +890,8 @@
 /*
  *  Main program
  */
+
+int yyparse();
 
 int main(int argc, char **argv)
 {
