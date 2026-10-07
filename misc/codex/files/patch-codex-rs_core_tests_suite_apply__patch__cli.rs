--- codex-rs/core/tests/suite/apply_patch_cli.rs.orig	2026-10-05 17:16:58 UTC
+++ codex-rs/core/tests/suite/apply_patch_cli.rs
@@ -2285,7 +2285,7 @@ async fn apply_patch_turn_diff_emits_portable_paths_fo
     let cwd = &test.executor_environment().selection().cwd;
     let file_uri = cwd.join(file)?;
     let expected_relative_path = match test_target_os() {
-        TestTargetOs::Linux | TestTargetOs::MacOs => "nested/foreign.txt",
+        TestTargetOs::Linux | TestTargetOs::MacOs | TestTargetOs::FreeBsd => "nested/foreign.txt",
         TestTargetOs::Windows => r"nested\foreign.txt",
     };
     assert_eq!(
