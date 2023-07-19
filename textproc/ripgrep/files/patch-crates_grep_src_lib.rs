--- crates/grep/src/lib.rs.orig	2023-07-19 16:11:20 UTC
+++ crates/grep/src/lib.rs
@@ -12,7 +12,7 @@ A cookbook and a guide are planned.
 A cookbook and a guide are planned.
 */
 
-#![deny(missing_docs)]
+//#![deny(missing_docs)]
 
 pub extern crate grep_cli as cli;
 pub extern crate grep_matcher as matcher;
