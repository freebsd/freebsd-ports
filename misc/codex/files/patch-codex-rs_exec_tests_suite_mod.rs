--- codex-rs/exec/tests/suite/mod.rs.orig	2026-07-21 17:29:35 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -13,5 +13,6 @@ mod resume;
 mod output_schema;
 mod prompt_stdin;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 mod server_error_exit;
