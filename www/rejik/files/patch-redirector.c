--- redirector.c.orig	2013-11-15 10:28:02 UTC
+++ redirector.c
@@ -4,6 +4,9 @@
 #include <errno.h>
 #include "vars.h"
 
+struct section **redir;
+char **allow_urls;
+int allow_urls_count;
 
 /***************************************
  ********** Start MAIN function ********/
