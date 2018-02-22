--- src/dom-api/impl/XPathDocumentImpl.cpp.orig	2017-09-03 19:24:35 UTC
+++ src/dom-api/impl/XPathDocumentImpl.cpp
@@ -62,7 +62,11 @@ DOMNode *XPathDocumentImpl::insertBefore
     if (thisNodeImpl->isReadOnly())
         throw DOMException(DOMException::NO_MODIFICATION_ALLOWED_ERR, 0, getMemoryManager());
 
+#if _XERCES_VERSION >= 30200
+    DOMNode* thisNode = fParent.fContainingNode;
+#else
     DOMNode* thisNode = castToNode(&fParent);
+#endif
     if (newChild->getOwnerDocument() != thisNode)
         throw DOMException(DOMException::WRONG_DOCUMENT_ERR, 0, getMemoryManager());
 
