--- src/conky.cc.orig	2026-05-17 15:16:39 UTC
+++ src/conky.cc
@@ -1857,10 +1857,12 @@ void get_system_details() {
   }
 #endif
 
-  if (info.system.wm_name != nullptr) {
-    LOG_INFO("'{}' {} session running", info.system.wm_name, session_ty);
-  } else {
-    LOG_INFO("unknown {} session running", session_ty);
+  if (session_ty != nullptr) {
+    if (info.system.wm_name != nullptr) {
+      LOG_INFO("'{}' {} session running", info.system.wm_name, session_ty);
+    } else {
+      LOG_INFO("unknown {} session running", session_ty);
+    }
   }
 }
 
