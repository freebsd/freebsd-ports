--- libxslt/imports.c.orig	2015-09-28 01:15:21 UTC
+++ libxslt/imports.c
@@ -131,10 +131,11 @@ xsltParseStylesheetImport(xsltStylesheetPtr style, xml
 	int secres;
 
 	secres = xsltCheckRead(sec, NULL, URI);
-	if (secres == 0) {
-	    xsltTransformError(NULL, NULL, NULL,
-		 "xsl:import: read rights for %s denied\n",
-			     URI);
+	if (secres <= 0) {
+            if (secres == 0)
+                xsltTransformError(NULL, NULL, NULL,
+                     "xsl:import: read rights for %s denied\n",
+                                 URI);
 	    goto error;
 	}
     }
