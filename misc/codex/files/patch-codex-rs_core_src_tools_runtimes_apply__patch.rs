--- codex-rs/core/src/tools/runtimes/apply_patch.rs.orig	2026-08-29 09:11:57 UTC
+++ codex-rs/core/src/tools/runtimes/apply_patch.rs
@@ -91,6 +91,16 @@ impl ApplyPatchRuntime {
         if !attempt.sandbox_requested {
             return None;
         }
+        // LOCAL: the sandboxed fs helper requires Landlock/seatbelt/Windows
+        // sandboxing and fails closed on FreeBSD with
+        // "filesystem sandbox cannot be enforced on this executor".
+        if !cfg!(any(
+            target_os = "linux",
+            target_os = "macos",
+            target_os = "windows"
+        )) {
+            return None;
+        }
 
         let permissions = effective_permission_profile(
             attempt.exec_server_permissions,
@@ -180,14 +190,24 @@ impl ToolRuntime<ApplyPatchRequest, ApplyPatchRuntimeO
             &req.action.patch,
             ApplyPatchOptions {
                 update_file_mode: req.action.update_file_mode(),
-                // Only reject links when an otherwise-required sandbox was bypassed.
-                // Executor-managed sandboxes can have SandboxType::None.
-                follow_symlinks: attempt.sandbox_requested
-                    || !attempt.manager.should_sandbox(
-                        attempt.permissions,
-                        self.sandbox_preference(),
-                        attempt.enforce_managed_network,
-                    ),
+                // Only reject links when an otherwise-required sandbox was
+                // bypassed. LOCAL: FreeBSD has no platform sandbox, so keep
+                // 0.148 follow-symlinks instead of no-follow (which rejects
+                // apply_patch with "require an absolute path").
+                follow_symlinks: if cfg!(any(
+                    target_os = "linux",
+                    target_os = "macos",
+                    target_os = "windows"
+                )) {
+                    attempt.sandbox_requested
+                        || !attempt.manager.should_sandbox(
+                            attempt.permissions,
+                            self.sandbox_preference(),
+                            attempt.enforce_managed_network,
+                        )
+                } else {
+                    true
+                },
             },
             &req.action.cwd,
             &mut stdout,
