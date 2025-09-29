--- codex-rs/exec/tests/suite/mod.rs.orig	2025-09-26 18:28:59 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -2,4 +2,5 @@ mod resume;
 mod apply_patch;
 mod output_schema;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
