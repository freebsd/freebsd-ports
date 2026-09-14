--- codex-rs/tui/src/main.rs.orig	2026-09-13 12:46:31 UTC
+++ codex-rs/tui/src/main.rs
@@ -1,3 +1,5 @@
+#![recursion_limit = "256"]
+
 use clap::Parser;
 use codex_arg0::Arg0DispatchPaths;
 use codex_arg0::arg0_dispatch_or_else;
