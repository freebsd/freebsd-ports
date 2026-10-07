--- codex-rs/chatgpt/src/lib.rs.orig	2026-10-07 05:16:40 UTC
+++ codex-rs/chatgpt/src/lib.rs
@@ -1,3 +1,5 @@
+#![recursion_limit = "256"]
+
 pub mod apply_command;
 mod chatgpt_client;
 pub mod connectors;
