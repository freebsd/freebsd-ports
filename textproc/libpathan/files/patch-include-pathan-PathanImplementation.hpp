--- include/pathan/PathanImplementation.hpp.orig	Fri Dec 22 15:28:34 2006
+++ include/pathan/PathanImplementation.hpp	Fri Dec 22 15:29:08 2006
@@ -184,7 +184,7 @@
    *   the feature to see if it requires this method.
    * @since DOM Level 2
    */ 
-  virtual XERCES_CPP_NAMESPACE_QUALIFIER DOMDocumentType *PathanImplementation::createDocumentType(const XMLCh *qualifiedName,const XMLCh * publicId, const XMLCh *systemId);
+  virtual XERCES_CPP_NAMESPACE_QUALIFIER DOMDocumentType *createDocumentType(const XMLCh *qualifiedName,const XMLCh * publicId, const XMLCh *systemId);
 
   /**
    * This method makes available a <code>DOMImplementation</code>'s
