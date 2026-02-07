--- include/Arcus/SocketListener.h.orig	2023-05-19 06:44:12 UTC
+++ include/Arcus/SocketListener.h
@@ -6,6 +6,8 @@
 
 #include "Arcus/Types.h"
 
+#include "ArcusExport.h"
+
 namespace Arcus
 {
 class Socket;
@@ -24,7 +26,7 @@ class Error;
  * signal from a subclass of this class, to make sure the actual event
  * is handled on the main thread.
  */
-class SocketListener
+class ARCUS_EXPORT SocketListener
 {
 public:
     SocketListener() : _socket(nullptr)
