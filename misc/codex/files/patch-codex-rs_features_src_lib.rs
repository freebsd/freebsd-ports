--- codex-rs/features/src/lib.rs.orig	2026-11-05 23:31:17 UTC
+++ codex-rs/features/src/lib.rs
@@ -1100,7 +1100,8 @@ pub const FEATURES: &[FeatureSpec] = &[
         id: Feature::DaemonAutoStart,
         key: "daemon_auto_start",
         stage: Stage::Stable,
-        default_enabled: true,
+        // FreeBSD has no packaged daemon or native PID-management backend.
+        default_enabled: !cfg!(target_os = "freebsd"),
     },
     FeatureSpec {
         id: Feature::TuiMultiBackend,
