--- third_party/repo.bzl.orig
+++ third_party/repo.bzl
@@ -62,13 +62,15 @@ def _repos_are_siblings():
     return Label("@foo//bar").workspace_root.startswith("../")

 # Apply a patch_file to the repository root directory
-# Runs 'git apply' on Unix, 'patch -p1' on Windows.
+# Runs 'patch -p1'
 def _apply_patch(ctx, patch_file):
-    if _is_windows(ctx):
-        patch_command = ["patch", "-p1", "-d", ctx.path("."), "-i", ctx.path(patch_file)]
-    else:
-        patch_command = ["git", "apply", "-v", ctx.path(patch_file)]
-    cmd = _wrap_bash_cmd(ctx, patch_command)
+    # Don't check patch on Windows, because patch is only available under bash.
+    if not _is_windows(ctx) and not ctx.which("patch"):
+        fail("patch command is not found, please install it")
+    cmd = _wrap_bash_cmd(
+        ctx,
+        ["patch", "-p1", "-d", ctx.path("."), "-i", ctx.path(patch_file)],
+    )
     _execute_and_check_ret_code(ctx, cmd)

 def _apply_delete(ctx, paths):

