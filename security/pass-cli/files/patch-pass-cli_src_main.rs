--- pass-cli/src/main.rs.orig	2026-07-26 13:42:27 UTC
+++ pass-cli/src/main.rs
@@ -17,6 +17,8 @@
  *
  */
 
+#![recursion_limit = "256"]
+
 #[macro_use]
 extern crate tracing;
 
