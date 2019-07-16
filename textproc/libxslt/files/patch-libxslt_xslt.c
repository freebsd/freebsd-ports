--- libxslt/xslt.c.orig	2017-10-26 07:55:47 UTC
+++ libxslt/xslt.c
@@ -6763,10 +6763,11 @@ xsltParseStylesheetFile(const xmlChar* filename) {
 	int res;
 
 	res = xsltCheckRead(sec, NULL, filename);
-	if (res == 0) {
-	    xsltTransformError(NULL, NULL, NULL,
-		 "xsltParseStylesheetFile: read rights for %s denied\n",
-			     filename);
+	if (res <= 0) {
+            if (res == 0)
+                xsltTransformError(NULL, NULL, NULL,
+                     "xsltParseStylesheetFile: read rights for %s denied\n",
+                                 filename);
 	    return(NULL);
 	}
     }
