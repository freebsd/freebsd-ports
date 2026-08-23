--- codex-rs/exec/tests/suite/mod.rs.orig	2026-08-20 20:09:38 UTC
+++ codex-rs/exec/tests/suite/mod.rs
@@ -13,6 +13,7 @@ mod resume;
 mod output_schema;
 mod prompt_stdin;
 mod resume;
+#[cfg(not(target_os = "freebsd"))]
 mod sandbox;
 #[cfg(target_os = "macos")]
 mod seatbelt;
