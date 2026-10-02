--- codex-rs/core/src/tools/runtimes/apply_patch.rs.orig	2026-09-18 19:04:49 UTC
+++ codex-rs/core/src/tools/runtimes/apply_patch.rs
@@ -5,6 +5,7 @@ use crate::session::turn_context::TurnEnvironment;
 //! sandboxing enforced by the explicit filesystem sandbox context.
 use crate::exec::is_likely_sandbox_denied;
 use crate::session::turn_context::TurnEnvironment;
+use crate::tools::handlers::apply_patch::apply_patch_file_system_sandbox;
 use crate::tools::sandboxing::Approvable;
 use crate::tools::sandboxing::ApprovalAction;
 use crate::tools::sandboxing::ExecApprovalRequirement;
@@ -174,6 +175,7 @@ impl ToolRuntime<ApplyPatchRequest, ApplyPatchRuntimeO
         let started_at = Instant::now();
         let fs = req.turn_environment.environment.get_filesystem();
         let sandbox = Self::file_system_sandbox_context_for_attempt(req, attempt);
+        let sandbox = apply_patch_file_system_sandbox(&req.turn_environment, sandbox.as_ref());
         let mut stdout = Vec::new();
         let mut stderr = Vec::new();
         let result = codex_apply_patch::apply_patch_with_options(
@@ -193,7 +195,7 @@ impl ToolRuntime<ApplyPatchRequest, ApplyPatchRuntimeO
             &mut stdout,
             &mut stderr,
             fs.as_ref(),
-            sandbox.as_ref(),
+            sandbox,
         )
         .await;
         let stdout = String::from_utf8_lossy(&stdout).into_owned();
