--- codex-rs/features/src/lib.rs.orig	1970-01-01 00:00:00 UTC
+++ codex-rs/features/src/lib.rs
@@ -1086,7 +1086,8 @@ pub const FEATURES: &[FeatureSpec] = &[
         id: Feature::DaemonAutoStart,
         key: "daemon_auto_start",
         stage: Stage::Stable,
-        default_enabled: true,
+        // FreeBSD has no packaged daemon or native PID-management backend.
+        default_enabled: !cfg!(target_os = "freebsd"),
     },
     FeatureSpec {
         id: Feature::TuiMultiBackend,
