--- libxslt/keys.c.orig	2017-12-02 03:58:51.000000000 -0500
+++ libxslt/keys.c	2019-06-12 08:38:40.214472000 -0400
@@ -629,6 +629,7 @@ xsltInitCtxtKey(xsltTransformContextPtr ctxt, xsltDocu
     xmlNodePtr oldContextNode;
     xsltDocumentPtr oldDocInfo;
     int	oldXPPos, oldXPSize;
+    xmlNodePtr oldXPNode;
     xmlDocPtr oldXPDoc;
     int oldXPNsNr;
     xmlNsPtr *oldXPNamespaces;
@@ -667,6 +668,7 @@ fprintf(stderr, "xsltInitCtxtKey %s : %d\n", keyDef->n
     oldDocInfo = ctxt->document;
     oldContextNode = ctxt->node;
 
+    oldXPNode = xpctxt->node;
     oldXPDoc = xpctxt->doc;
     oldXPPos = xpctxt->proximityPosition;
     oldXPSize = xpctxt->contextSize;
@@ -865,6 +867,7 @@ error:
     /*
     * Restore context state.
     */
+    xpctxt->node = oldXPNode;
     xpctxt->doc = oldXPDoc;
     xpctxt->nsNr = oldXPNsNr;
     xpctxt->namespaces = oldXPNamespaces;
