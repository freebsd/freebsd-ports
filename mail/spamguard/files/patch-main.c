--- main.c.orig	2007-05-07 06:38:05 UTC
+++ main.c
@@ -27,11 +27,6 @@
 #include "qsheff_parser.h"
 #include "config.h"
 
-extern char logtype[VALSIZE];
-extern char logfile[VALSIZE];
-extern char ignorefile[VALSIZE];
-extern char badmailfile[VALSIZE];
-
 int w = 0;
 int b = 0;
 int p = 0;
