--- codex-rs/exec/tests/suite/mod.rs.orig	2025-10-25 21:16:34 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -4,5 +4,6 @@ mod resume;
 mod originator;
 mod output_schema;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 mod server_error_exit;
