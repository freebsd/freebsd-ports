--- mls_text.c.orig	2003-05-27 20:07:13 UTC
+++ mls_text.c
@@ -22,9 +22,6 @@
 #include "mls_lang.h"
 #include "mls_stat.h"
 
-// because we must specify it when 2dimensional array is passed to function
-#define SNUMB_LEN	4
-
 extern int lang;
 extern int graph;
 extern int onlytitle;
