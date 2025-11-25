--- codex-rs/exec/tests/suite/mod.rs.orig	2025-11-21 18:00:38 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -5,5 +5,6 @@ mod resume;
 mod originator;
 mod output_schema;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 mod server_error_exit;
