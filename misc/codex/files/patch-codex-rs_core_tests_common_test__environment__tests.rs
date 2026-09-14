--- codex-rs/core/tests/common/test_environment_tests.rs.orig	2026-09-13 21:01:39 UTC
+++ codex-rs/core/tests/common/test_environment_tests.rs
@@ -125,6 +125,8 @@ fn derives_target_operating_system_and_placement() {
     let expected_local_target_os = TestTargetOs::MacOs;
     #[cfg(target_os = "windows")]
     let expected_local_target_os = TestTargetOs::Windows;
+    #[cfg(target_os = "freebsd")]
+    let expected_local_target_os = TestTargetOs::FreeBsd;
 
     let environments = [
         TestEnvironment::Local,
