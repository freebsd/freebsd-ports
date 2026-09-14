--- codex-rs/app-server/tests/all.rs.orig	2026-09-13 10:28:42 UTC
+++ codex-rs/app-server/tests/all.rs
@@ -1,3 +1,5 @@
+#![recursion_limit = "256"]
+
 #![allow(clippy::expect_used)]
 
 // Single integration test binary that aggregates all test modules.
