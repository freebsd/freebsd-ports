--- codex-rs/exec/tests/suite/mod.rs.orig	2026-02-12 19:27:09 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -7,5 +7,6 @@ mod resume;
 mod originator;
 mod output_schema;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 mod server_error_exit;
