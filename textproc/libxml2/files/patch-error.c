--- error.c.orig	Tue Nov  9 21:08:54 2004
+++ error.c	Tue Nov  9 21:09:05 2004
@@ -453,7 +453,7 @@
         return;
     if ((domain == XML_FROM_PARSER) || (domain == XML_FROM_HTML) ||
         (domain == XML_FROM_DTD) || (domain == XML_FROM_NAMESPACE) ||
-	(domain == XML_FROM_IO) || (domain == XML_FROM_VALID)) {
+	(domain == XML_FROM_IO)) {
 	ctxt = (xmlParserCtxtPtr) ctx;
 	if ((schannel == NULL) && (ctxt != NULL) && (ctxt->sax != NULL) &&
 	    (ctxt->sax->initialized == XML_SAX2_MAGIC))
