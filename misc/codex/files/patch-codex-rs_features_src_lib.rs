--- codex-rs/features/src/lib.rs.orig	2026-10-27 18:19:19 UTC
+++ codex-rs/features/src/lib.rs
@@ -1069,7 +1069,8 @@ pub const FEATURES: &[FeatureSpec] = &[
         id: Feature::DaemonAutoStart,
         key: "daemon_auto_start",
         stage: Stage::Stable,
-        default_enabled: true,
+        // FreeBSD has no packaged daemon or native PID-management backend.
+        default_enabled: !cfg!(target_os = "freebsd"),
     },
     FeatureSpec {
         id: Feature::TuiMultiBackend,
