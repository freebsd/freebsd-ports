--- include/xqilla/events/EventSerializer.hpp.orig	2015-05-18 17:38:59 UTC
+++ include/xqilla/events/EventSerializer.hpp
@@ -35,7 +35,9 @@ public:
                   XERCES_CPP_NAMESPACE_QUALIFIER XMLPlatformUtils::fgMemoryManager);
   ~EventSerializer();
 
-  virtual void setLocationInfo(const LocationInfo *location) {}
+  virtual void setLocationInfo(const LocationInfo *location) {
+	  (void) location;
+  }
 
   virtual void startDocumentEvent(const XMLCh *documentURI, const XMLCh *encoding);
   virtual void endDocumentEvent();
