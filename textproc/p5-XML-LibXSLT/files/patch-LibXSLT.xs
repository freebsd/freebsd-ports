--- LibXSLT.xs.orig	Mon Mar  1 18:42:43 2004
+++ LibXSLT.xs	Mon Apr 11 08:07:33 2005
@@ -772,6 +772,7 @@
         xmlDocPtr real_dom;
         xmlDocPtr doc;
         STRLEN len;
+        xsltTransformContextPtr ctxt;
     CODE:
         if (sv_doc == NULL) {
             XSRETURN_UNDEF;
@@ -806,10 +807,21 @@
                               (xmlInputOpenCallback) LibXSLT_input_open,
                               (xmlInputReadCallback) LibXSLT_input_read,
                               (xmlInputCloseCallback) LibXSLT_input_close);
-        real_dom = xsltApplyStylesheet(self, doc, xslt_params);
+        
+        ctxt = xsltNewTransformContext(self, doc);
+        if (ctxt == NULL)
+                return;
+
+        xsltSetCtxtParseOptions(ctxt, 0);
+
+        if (xsltGetXIncludeDefault())
+                ctxt->xinclude = 1;
+
+        real_dom = xsltApplyStylesheetUser(self, doc, xslt_params, NULL, NULL, ctxt);
 
         xmlCleanupInputCallbacks();
         xmlRegisterDefaultInputCallbacks();
+        xsltFreeTransformContext(ctxt);
 
         if (real_dom == NULL) {
             if (SvTRUE(ERRSV)) {
