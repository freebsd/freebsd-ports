--- ipaserver/install/kra.py.orig	2026-08-09 15:49:25 UTC
+++ ipaserver/install/kra.py
@@ -204,9 +204,10 @@ def uninstall():
 
 def uninstall():
     kra = krainstance.KRAInstance(api.env.realm)
+    if not kra.is_installed():
+        return
     kra.stop_tracking_certificates()
-    if kra.is_installed():
-        kra.uninstall()
+    kra.uninstall()
 
 
 @group
