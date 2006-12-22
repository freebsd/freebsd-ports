--- include/pathan/XPath2Utils.hpp.orig	Fri Dec 22 15:25:39 2006
+++ include/pathan/XPath2Utils.hpp	Fri Dec 22 15:26:03 2006
@@ -62,7 +62,7 @@
   static std::vector<const XMLCh*> getVal(const XMLCh* values, XPath2MemoryManager* memMgr);
 
   /* Determine whether or not an XMLCh* is contained within a vector of XMLCh's */
-  static bool XPath2Utils::containsString(std::vector<const XMLCh*> values, const XMLCh* val); 
+  static bool containsString(std::vector<const XMLCh*> values, const XMLCh* val); 
 
   /** Obtain index of node with respect to it's siblings of same name */
   static int indexNode(const XERCES_CPP_NAMESPACE_QUALIFIER DOMNode *node);
