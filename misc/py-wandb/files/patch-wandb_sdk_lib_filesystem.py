--- wandb/sdk/lib/filesystem.py.orig	2026-04-28 03:26:49 UTC
+++ wandb/sdk/lib/filesystem.py
@@ -315,6 +315,8 @@ def reflink(existing_path: StrPath, new_path: StrPath,
     """
     if platform.system() == "Linux":
         link_fn = _reflink_linux
+    elif platform.system() == "FreeBSD":
+        link_fn = _reflink_linux
     elif platform.system() == "Darwin":
         link_fn = _reflink_macos
     else:
