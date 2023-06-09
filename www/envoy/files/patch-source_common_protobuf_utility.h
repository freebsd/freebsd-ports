--- source/common/protobuf/utility.h.orig	2023-04-27 12:00:08 UTC
+++ source/common/protobuf/utility.h
@@ -317,10 +317,12 @@ class MessageUtil { (public)
     // at top level ingestion (bootstrap, discovery response). This is a large change and will be
     // done as a separate PR. This change will also allow removing templating from most/all of
     // related functions.
+#if notyet
     std::string err;
     if (!Validate(message, &err)) {
       ProtoExceptionUtil::throwProtoValidationException(err, message);
     }
+#endif
   }
 
   template <class MessageType>
