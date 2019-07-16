--- libxslt/transform.c.orig	2017-10-30 07:49:55 UTC
+++ libxslt/transform.c
@@ -3485,10 +3485,11 @@ xsltDocumentElem(xsltTransformContextPtr ctxt, xmlNode
      */
     if (ctxt->sec != NULL) {
 	ret = xsltCheckWrite(ctxt->sec, ctxt, filename);
-	if (ret == 0) {
-	    xsltTransformError(ctxt, NULL, inst,
-		 "xsltDocumentElem: write rights for %s denied\n",
-			     filename);
+	if (ret <= 0) {
+            if (ret == 0)
+                xsltTransformError(ctxt, NULL, inst,
+                     "xsltDocumentElem: write rights for %s denied\n",
+                                 filename);
 	    xmlFree(URL);
 	    xmlFree(filename);
 	    return;
