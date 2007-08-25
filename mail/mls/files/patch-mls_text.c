--- mls_text.c.orig	2007-08-26 03:28:10.000000000 +0800
+++ mls_text.c	2007-08-26 03:28:32.000000000 +0800
@@ -22,9 +22,6 @@
 #include "mls_lang.h"
 #include "mls_stat.h"
 
-// because we must specify it when 2dimensional array is passed to function
-#define SNUMB_LEN	4
-
 extern int lang;
 extern int graph;
 extern int onlytitle;
