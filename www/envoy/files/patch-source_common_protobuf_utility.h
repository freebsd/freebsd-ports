--- source/common/protobuf/utility.h.orig	2019-04-05 18:07:44 UTC
+++ source/common/protobuf/utility.h
@@ -222,10 +222,12 @@ class MessageUtil { (public)
     // Log warnings or throw errors if deprecated fields are in use.
     checkForDeprecation(message);
 
+#if notyet
     std::string err;
     if (!Validate(message, &err)) {
       throw ProtoValidationException(err, message);
     }
+#endif
   }
 
   template <class MessageType>
