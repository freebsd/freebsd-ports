--- libxslt/transform.c.orig	Sat Nov 10 13:35:49 2001
+++ libxslt/transform.c	Mon Dec  3 00:03:39 2001
@@ -3474,12 +3474,10 @@
             if (tmp == root) {
                 ctxt->type = XSLT_OUTPUT_HTML;
                 res->type = XML_HTML_DOCUMENT_NODE;
-                if (((doctypePublic != NULL) || (doctypeSystem != NULL)))
+                if (((doctypePublic != NULL) || (doctypeSystem != NULL))) {
                     res->intSubset = xmlCreateIntSubset(res, root->name,
                                                         doctypePublic,
                                                         doctypeSystem);
-		if (((doctypePublic != NULL) || (doctypeSystem != NULL))) {
-		    res = htmlNewDoc(doctypeSystem, doctypePublic);
 #ifdef XSLT_GENERATE_HTML_DOCTYPE
 		} else if (version != NULL) {
                     xsltGetHTMLIDs(version, &doctypePublic,
