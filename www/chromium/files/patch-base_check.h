--- base/check.h.orig	2021-04-22 11:38:19 UTC
+++ base/check.h
@@ -85,7 +85,7 @@ class BASE_EXPORT CheckError {
   // Stream for adding optional details to the error message.
   std::ostream& stream();
 
-  NOMERGE ~CheckError();
+  ~CheckError();
 
   CheckError(const CheckError& other) = delete;
   CheckError& operator=(const CheckError& other) = delete;
