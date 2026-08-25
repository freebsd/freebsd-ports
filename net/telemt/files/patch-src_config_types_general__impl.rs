--- src/config/types/general_impl.rs.orig	2026-08-27 19:11:44 UTC
+++ src/config/types/general_impl.rs
@@ -1,9 +1,13 @@ use super::*;
 use super::*;
 
+pub(super) fn default_data_path() -> Option<PathBuf> {
+    Some(PathBuf::from("/var/db/telemt"))
+}
+
 impl Default for GeneralConfig {
     fn default() -> Self {
         Self {
-            data_path: None,
+            data_path: default_data_path(),
             quota_state_path: default_quota_state_path(),
             config_strict: false,
             modes: ProxyModes::default(),
