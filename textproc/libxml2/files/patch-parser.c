--- parser.c.orig	Mon Nov 25 00:39:37 2002
+++ parser.c	Mon Nov 25 01:49:31 2002
@@ -9820,7 +9820,7 @@
 	ctxt->myDoc = oldctxt->myDoc;
         content = ctxt->myDoc->children;
     }
-    ctxt->myDoc->children = xmlNewDocNode(newDoc, NULL,
+    ctxt->myDoc->children = xmlNewDocNode(ctxt->myDoc, NULL,
 	                                  BAD_CAST "pseudoroot", NULL);
     if (ctxt->myDoc->children == NULL) {
 	ctxt->sax = oldsax;
