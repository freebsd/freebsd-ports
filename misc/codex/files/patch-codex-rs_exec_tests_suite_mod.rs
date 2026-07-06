--- codex-rs/exec/tests/suite/mod.rs.orig	2026-06-18 03:59:28 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -11,5 +11,6 @@ mod resume;
 mod output_schema;
 mod prompt_stdin;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 mod server_error_exit;
