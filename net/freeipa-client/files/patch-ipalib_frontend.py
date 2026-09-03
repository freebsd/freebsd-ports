--- ipalib/frontend.py.orig	2026-07-08 19:34:13 UTC
+++ ipalib/frontend.py
@@ -481,7 +481,10 @@ class Command(HasParam):
             return
         setattr(context, 'audit_action', None)
 
-        from systemd import journal
+        try:
+            from systemd import journal
+        except ImportError:
+            return
         from ipalib.ipajson import json_encode_binary
         args_opts = dict([*self._safe_args_and_params(**params)])
         json_encoded = json_encode_binary(args_opts, API_VERSION,
