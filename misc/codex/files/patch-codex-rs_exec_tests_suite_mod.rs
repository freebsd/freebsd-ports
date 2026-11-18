--- codex-rs/exec/tests/suite/mod.rs.orig	2026-11-18 02:28:28 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -17,6 +17,7 @@ mod resume;
 mod output_schema;
 mod prompt_stdin;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 #[cfg(target_os = "macos")]
 mod seatbelt;
