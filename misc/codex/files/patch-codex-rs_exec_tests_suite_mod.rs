--- codex-rs/exec/tests/suite/mod.rs.orig	2026-06-09 19:02:39 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -10,5 +10,6 @@ mod resume;
 mod output_schema;
 mod prompt_stdin;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 mod server_error_exit;
