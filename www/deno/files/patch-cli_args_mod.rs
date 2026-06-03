Ignore unstable-tsgo flag

Index: cli/args/mod.rs
--- cli/args/mod.rs.orig
+++ cli/args/mod.rs
@@ -1242,7 +1242,7 @@ impl CliOptions {
   }
 
   pub fn unstable_tsgo(&self) -> bool {
-    self.flags.unstable_config.tsgo || self.workspace().has_unstable("tsgo")
+    false
   }
 
   pub fn unsafely_ignore_certificate_errors(&self) -> &Option<Vec<String>> {
