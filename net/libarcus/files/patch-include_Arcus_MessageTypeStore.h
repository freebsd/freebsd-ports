--- include/Arcus/MessageTypeStore.h.orig	2023-05-19 06:44:12 UTC
+++ include/Arcus/MessageTypeStore.h
@@ -8,12 +8,14 @@
 
 #include "Arcus/Types.h"
 
+#include "ArcusExport.h"
+
 namespace Arcus
 {
 /**
  * A class to manage the different types of messages that are available.
  */
-class MessageTypeStore
+class ARCUS_EXPORT MessageTypeStore
 {
 public:
     MessageTypeStore();
@@ -87,7 +89,7 @@ class MessageTypeStore (private)
     void dumpMessageTypes();
 
 private:
-    class Private;
+    class ARCUS_NO_EXPORT Private;
     const std::unique_ptr<Private> d;
 };
 } // namespace Arcus
