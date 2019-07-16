--- libxslt/documents.c.orig	2015-05-10 14:11:29 UTC
+++ libxslt/documents.c
@@ -296,10 +296,11 @@ xsltLoadDocument(xsltTransformContextPtr ctxt, const x
 	int res;
 
 	res = xsltCheckRead(ctxt->sec, ctxt, URI);
-	if (res == 0) {
-	    xsltTransformError(ctxt, NULL, NULL,
-		 "xsltLoadDocument: read rights for %s denied\n",
-			     URI);
+	if (res <= 0) {
+            if (res == 0)
+                xsltTransformError(ctxt, NULL, NULL,
+                     "xsltLoadDocument: read rights for %s denied\n",
+                                 URI);
 	    return(NULL);
 	}
     }
@@ -372,10 +373,11 @@ xsltLoadStyleDocument(xsltStylesheetPtr style, const x
 	int res;
 
 	res = xsltCheckRead(sec, NULL, URI);
-	if (res == 0) {
-	    xsltTransformError(NULL, NULL, NULL,
-		 "xsltLoadStyleDocument: read rights for %s denied\n",
-			     URI);
+	if (res <= 0) {
+            if (res == 0)
+                xsltTransformError(NULL, NULL, NULL,
+                     "xsltLoadStyleDocument: read rights for %s denied\n",
+                                 URI);
 	    return(NULL);
 	}
     }
