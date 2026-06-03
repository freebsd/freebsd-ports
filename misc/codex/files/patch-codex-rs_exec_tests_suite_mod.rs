--- codex-rs/exec/tests/suite/mod.rs.orig	2026-04-11 01:58:04 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -8,5 +8,6 @@ mod resume;
 mod output_schema;
 mod prompt_stdin;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 mod server_error_exit;
