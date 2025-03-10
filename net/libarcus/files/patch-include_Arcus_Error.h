--- include/Arcus/Error.h.orig	2023-05-19 06:44:12 UTC
+++ include/Arcus/Error.h
@@ -5,6 +5,7 @@
 #define ARCUS_ERROR_H
 
 #include "Arcus/Types.h"
+#include "ArcusExport.h"
 
 namespace Arcus
 {
@@ -32,7 +33,7 @@ enum class ErrorCode
 /**
  * A class representing an error with an error code and an error message.
  */
-class Error
+class ARCUS_EXPORT Error
 {
 public:
     /**
