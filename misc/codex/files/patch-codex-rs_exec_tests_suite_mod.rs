--- codex-rs/exec/tests/suite/mod.rs.orig	2026-10-08 16:56:07 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -16,6 +16,7 @@ mod resume;
 mod output_schema;
 mod prompt_stdin;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 #[cfg(target_os = "macos")]
 mod seatbelt;
