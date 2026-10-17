--- codex-rs/app-server-client/src/lib.rs.orig	2026-10-15 18:57:07 UTC
+++ codex-rs/app-server-client/src/lib.rs
@@ -20,6 +20,8 @@
 //! runtime remain bounded; the local consumer event queue is unbounded so
 //! unread notifications cannot prevent request responses from being delivered.
 
+#![recursion_limit = "256"]
+
 mod path;
 mod remote;
 mod server_request;
