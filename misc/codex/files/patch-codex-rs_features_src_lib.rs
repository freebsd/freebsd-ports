--- codex-rs/features/src/lib.rs.orig	2026-10-07 05:07:20 UTC
+++ codex-rs/features/src/lib.rs
@@ -948,7 +948,8 @@ pub const FEATURES: &[FeatureSpec] = &[
         id: Feature::DaemonAutoStart,
         key: "daemon_auto_start",
         stage: Stage::Stable,
-        default_enabled: true,
+        // FreeBSD has no packaged daemon or native PID-management backend.
+        default_enabled: !cfg!(target_os = "freebsd"),
     },
     FeatureSpec {
         id: Feature::TranscriptV2,
