--- codex-rs/exec/src/main.rs.orig	2026-10-15 18:57:07 UTC
+++ codex-rs/exec/src/main.rs
@@ -13,6 +13,9 @@
 //!
 //! This allows us to ship a completely separate set of functionality as part
 //! of the `codex-exec` binary.
+
+#![recursion_limit = "256"]
+
 use clap::Parser;
 use codex_arg0::Arg0DispatchPaths;
 use codex_arg0::arg0_dispatch_or_else;
