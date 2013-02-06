--- ../generic/url.c.orig	2013-02-05 13:56:35.000000000 +0100
+++ ../generic/url.c	2013-02-05 13:58:36.000000000 +0100
@@ -61,7 +61,10 @@
     PORT,
     SCRIPTNAME,
     PATHINFO,
-    QUERYSTRING
+    QUERYSTRING,
+    URLCFGRESET,
+    URLCFGURLFORMAT,
+    URLCFGEND 
 };
 
 
@@ -362,7 +365,7 @@
     Tcl_Obj *tmp = NULL;
     int errCnt = 0;
 
-    if ((urlData == NULL))
+    if (urlData == NULL)
 	return NULL;
 
     errCnt = 0;
@@ -840,10 +843,6 @@
 {
 
 
-#define URLCFGRESET (enum urlElement)QUERYSTRING+1
-#define URLCFGURLFORMAT (enum urlElement)QUERYSTRING+2
-#define URLCFGEND (enum urlElement)QUERYSTRING+3
-
     UrlData *urlData = NULL;
     /* note: this could be dynamic, but 20 is enough ... */
     char *params[20];
