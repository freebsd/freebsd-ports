--- include/Arcus/Socket.h.orig	2023-05-19 06:44:12 UTC
+++ include/Arcus/Socket.h
@@ -9,6 +9,8 @@
 #include "Arcus/Error.h"
 #include "Arcus/Types.h"
 
+#include "ArcusExport.h"
+
 namespace Arcus
 {
 class SocketListener;
@@ -21,7 +23,7 @@ class SocketListener;
  *
  * Please see the README in libArcus for more details.
  */
-class Socket
+class ARCUS_EXPORT Socket
 {
 public:
     Socket();
