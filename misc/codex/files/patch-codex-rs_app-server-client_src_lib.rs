--- codex-rs/app-server-client/src/lib.rs.orig	2026-09-13 18:14:32 UTC
+++ codex-rs/app-server-client/src/lib.rs
@@ -16,6 +16,8 @@
 //! runtime remain bounded; the local consumer event queue is unbounded so
 //! unread notifications cannot prevent request responses from being delivered.
 
+#![recursion_limit = "256"]
+
 mod path;
 mod remote;
 
