Ignore unstable-tsgo flag

Index: cli/args/mod.rs
--- cli/args/mod.rs.orig	2026-09-16 15:45:55 UTC
+++ cli/args/mod.rs
@@ -1439,7 +1439,7 @@ impl CliOptions {
   }
 
   pub fn unstable_tsgo(&self) -> bool {
-    self.flags.unstable_config.tsgo || self.workspace().has_unstable("tsgo")
+    false
   }
 
   pub fn unsafely_ignore_certificate_errors(&self) -> &Option<Vec<String>> {
