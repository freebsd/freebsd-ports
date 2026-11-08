--- ipaclient/install/client.py.orig	2026-09-05 20:54:40 UTC
+++ ipaclient/install/client.py
@@ -728,6 +728,8 @@ def configure_krb5_snippet():
         paths.USR_SHARE_IPA_CLIENT_DIR,
         os.path.basename(paths.KRB5_FREEIPA_DEFAULTS) + ".template"
     )
+    os.makedirs(os.path.dirname(paths.KRB5_FREEIPA_DEFAULTS),
+                mode=0o755, exist_ok=True)
     shutil.copy(template, paths.KRB5_FREEIPA_DEFAULTS)
     os.chmod(paths.KRB5_FREEIPA_DEFAULTS, 0o644)
     tasks.restore_context(paths.KRB5_FREEIPA_DEFAULTS)
