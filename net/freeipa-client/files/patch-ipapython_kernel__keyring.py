--- ipapython/kernel_keyring.py.orig	2026-07-08 20:52:49 UTC
+++ ipapython/kernel_keyring.py
@@ -80,6 +80,9 @@ def is_persistent_keyring_supported(check_container=Tr
     If check_container is True and a containerized environment is detected,
     return False. There is no support for keyring namespace isolation yet.
     """
+    if not os.path.exists(paths.KEYCTL):
+        return False
+
     if check_container and tasks.detect_container() is not None:
         return False
     uid = os.geteuid()
