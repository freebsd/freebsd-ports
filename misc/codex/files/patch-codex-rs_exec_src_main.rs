--- codex-rs/exec/src/main.rs.orig	2026-09-13 10:30:38 UTC
+++ codex-rs/exec/src/main.rs
@@ -9,6 +9,9 @@
 //!
 //! This allows us to ship a completely separate set of functionality as part
 //! of the `codex-exec` binary.
+
+#![recursion_limit = "256"]
+
 use clap::Parser;
 use codex_arg0::Arg0DispatchPaths;
 use codex_arg0::arg0_dispatch_or_else;
