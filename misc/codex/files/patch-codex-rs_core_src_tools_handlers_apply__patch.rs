--- codex-rs/core/src/tools/handlers/apply_patch.rs.orig	2026-09-09 21:43:48 UTC
+++ codex-rs/core/src/tools/handlers/apply_patch.rs
@@ -43,6 +43,7 @@ use codex_exec_server::ExecutorFileSystem;
 use codex_apply_patch::Hunk;
 use codex_apply_patch::StreamingPatchParser;
 use codex_exec_server::ExecutorFileSystem;
+use codex_exec_server::FileSystemSandboxContext;
 use codex_features::Feature;
 use codex_protocol::models::AdditionalPermissionProfile;
 use codex_protocol::models::FileSystemPermissions;
@@ -72,6 +73,23 @@ fn apply_patch_file_update_mode(turn: &TurnContext) ->
     }
 }
 
+fn apply_patch_verification_sandbox<'a>(
+    environment: &TurnEnvironment,
+    sandbox: &'a FileSystemSandboxContext,
+) -> Option<&'a FileSystemSandboxContext> {
+    if cfg!(any(target_os = "openbsd", target_os = "freebsd"))
+        && !environment.environment.is_remote()
+        && environment
+            .permission_profile_with_workspace_roots()
+            .file_system_sandbox_policy()
+            .has_full_disk_read_access()
+    {
+        None
+    } else {
+        Some(sandbox)
+    }
+}
+
 /// Handles freeform `apply_patch` requests and routes verified patches to the
 /// selected environment filesystem.
 #[derive(Default)]
@@ -400,12 +418,14 @@ impl ApplyPatchHandler {
         };
         let fs = turn_environment.environment.get_filesystem();
         let sandbox = turn_environment.sandbox_context(/*additional_permissions*/ None);
+        let verification_sandbox =
+            apply_patch_verification_sandbox(turn_environment, &sandbox);
         match codex_apply_patch::verify_apply_patch_args_with_mode(
             args,
             turn_environment.cwd(),
             apply_patch_file_update_mode(&turn),
             fs.as_ref(),
-            Some(&sandbox),
+            verification_sandbox,
         )
         .await
         {
@@ -510,12 +530,13 @@ pub(crate) async fn intercept_apply_patch(
 ) -> Result<Option<FunctionToolOutput>, FunctionCallError> {
     let turn = &step_context.turn;
     let sandbox = turn_environment.sandbox_context(/*additional_permissions*/ None);
+    let verification_sandbox = apply_patch_verification_sandbox(&turn_environment, &sandbox);
     match codex_apply_patch::maybe_parse_apply_patch_verified_with_mode(
         command,
         cwd,
         apply_patch_file_update_mode(turn),
         fs,
-        Some(&sandbox),
+        verification_sandbox,
     )
     .await
     {
