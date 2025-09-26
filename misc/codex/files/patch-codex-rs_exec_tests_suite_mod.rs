--- codex-rs/exec/tests/suite/mod.rs.orig	2025-09-24 16:56:31 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -3,4 +3,5 @@ mod resume;
 mod common;
 mod output_schema;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
