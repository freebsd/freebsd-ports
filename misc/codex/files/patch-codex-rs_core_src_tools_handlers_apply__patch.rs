--- codex-rs/core/src/tools/handlers/apply_patch.rs.orig	2026-10-08 16:56:07 UTC
+++ codex-rs/core/src/tools/handlers/apply_patch.rs
@@ -45,6 +45,7 @@ use codex_exec_server::ExecutorFileSystem;
 use codex_apply_patch::Hunk;
 use codex_apply_patch::StreamingPatchParser;
 use codex_exec_server::ExecutorFileSystem;
+use codex_exec_server::FileSystemSandboxContext;
 use codex_features::Feature;
 use codex_protocol::models::AdditionalPermissionProfile;
 use codex_protocol::models::FileSystemPermissions;
@@ -60,6 +61,23 @@ const APPLY_PATCH_ARGUMENT_DIFF_BUFFER_INTERVAL: Durat
 
 const APPLY_PATCH_ARGUMENT_DIFF_BUFFER_INTERVAL: Duration = Duration::from_millis(500);
 
+pub(crate) fn apply_patch_file_system_sandbox<'a>(
+    environment: &TurnEnvironment,
+    sandbox: Option<&'a FileSystemSandboxContext>,
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
+        sandbox
+    }
+}
+
 /// Handles freeform `apply_patch` requests and routes verified patches to the
 /// selected environment filesystem.
 #[derive(Default)]
@@ -338,11 +356,13 @@ impl ApplyPatchHandler {
         )?;
         let fs = turn_environment.environment.get_filesystem();
         let sandbox = turn_environment.sandbox_context(/*additional_permissions*/ None);
+        let verification_sandbox =
+            apply_patch_file_system_sandbox(turn_environment, Some(&sandbox));
         match codex_apply_patch::verify_apply_patch_args(
             args,
             turn_environment.cwd(),
             fs.as_ref(),
-            Some(&sandbox),
+            verification_sandbox,
         )
         .await
         {
@@ -446,7 +466,8 @@ pub(crate) async fn intercept_apply_patch(
     tool_name: &str,
 ) -> Result<Option<FunctionToolOutput>, FunctionCallError> {
     let sandbox = turn_environment.sandbox_context(/*additional_permissions*/ None);
-    match codex_apply_patch::maybe_parse_apply_patch_verified(command, cwd, fs, Some(&sandbox))
+    let verification_sandbox = apply_patch_file_system_sandbox(&turn_environment, Some(&sandbox));
+    match codex_apply_patch::maybe_parse_apply_patch_verified(command, cwd, fs, verification_sandbox)
         .await
     {
         codex_apply_patch::MaybeApplyPatchVerified::Body(changes) => {
