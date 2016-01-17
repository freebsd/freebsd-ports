--- include/xqilla/events/EventHandler.hpp.orig	2015-05-18 17:38:59 UTC
+++ include/xqilla/events/EventHandler.hpp
@@ -33,7 +33,9 @@ public:
 
   /** Recieves a LocationInfo object that is owned by the caller, and will be
       updated with the current location information as the parse progresses. */
-  virtual void setLocationInfo(const LocationInfo *location) {}
+  virtual void setLocationInfo(const LocationInfo *location) {
+	  (void) location;
+  }
 
   /** Handles a document node as an event */
   virtual void startDocumentEvent(const XMLCh *documentURI, const XMLCh *encoding) = 0;
@@ -59,7 +61,12 @@ public:
   virtual void namespaceEvent(const XMLCh *prefix, const XMLCh *uri) = 0;
   /** Handles an atomic item as an event */
   virtual void atomicItemEvent(AnyAtomicType::AtomicObjectType type, const XMLCh *value,
-                               const XMLCh *typeURI, const XMLCh *typeName) {}
+                               const XMLCh *typeURI, const XMLCh *typeName) {
+	  (void) type;
+	  (void) value;
+	  (void) typeURI;
+	  (void) typeName;
+  }
   /** Called when all events have been reported */
   virtual void endEvent() = 0;
 };
