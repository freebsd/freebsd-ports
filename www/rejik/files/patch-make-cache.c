--- make-cache.c.orig	2013-11-15 10:28:02 UTC
+++ make-cache.c
@@ -2,6 +2,8 @@
 #include <string.h>
 #include "vars.h"
 
+struct section **redir;
+
 /***************************************
  ********** Start MAIN function ********/
  int main(int argc, char* argv[])
