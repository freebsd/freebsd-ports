--- codex-rs/exec/tests/suite/mod.rs.orig	2025-10-03 16:43:33 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -3,5 +3,6 @@ mod resume;
 mod auth_env;
 mod output_schema;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 mod server_error_exit;
