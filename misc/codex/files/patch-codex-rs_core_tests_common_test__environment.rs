--- codex-rs/core/tests/common/test_environment.rs.orig	2026-09-13 20:59:59 UTC
+++ codex-rs/core/tests/common/test_environment.rs
@@ -14,6 +14,7 @@ pub enum TestTargetOs {
     Linux,
     MacOs,
     Windows,
+    FreeBsd,
 }
 
 impl TestTargetOs {
@@ -24,6 +25,8 @@ impl TestTargetOs {
             Self::Windows
         } else if cfg!(target_os = "linux") {
             Self::Linux
+        } else if cfg!(target_os = "freebsd") {
+            Self::FreeBsd
         } else {
             unreachable!()
         }
@@ -31,7 +34,7 @@ impl TestTargetOs {
 
     const fn path_convention(self) -> PathConvention {
         match self {
-            Self::Linux | Self::MacOs => PathConvention::Posix,
+            Self::Linux | Self::MacOs | Self::FreeBsd => PathConvention::Posix,
             Self::Windows => PathConvention::Windows,
         }
     }
