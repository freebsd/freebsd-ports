--- parser.c.orig	2007-05-04 06:37:36 UTC
+++ parser.c
@@ -14,8 +14,6 @@
 #include "loadconfig.h"
 #include "parser.h"
 
-extern char logtype[VALSIZE];
-
 void
 read_logfile(char *fn) 
 {	
