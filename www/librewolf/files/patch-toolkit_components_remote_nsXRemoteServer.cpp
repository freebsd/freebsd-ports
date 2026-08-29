--- toolkit/components/remote/nsXRemoteServer.cpp.orig	2026-08-24 20:18:35 UTC
+++ toolkit/components/remote/nsXRemoteServer.cpp
@@ -110,7 +110,7 @@ bool nsXRemoteServer::HandleNewProperty(XID aWindowId,
 
     // Failed to get property off the window or
     // got a part only
-    if (result != Success || bytes_after != 0) {
+    if (result != X11Success || bytes_after != 0) {
       return false;
     }
 
