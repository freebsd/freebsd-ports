--- src/config/types/general.rs.orig	2026-08-31 00:16:15 UTC
+++ src/config/types/general.rs
@@ -1,7 +1,7 @@ pub struct GeneralConfig {
 use super::*;
 #[derive(Debug, Clone, Serialize, Deserialize)]
 pub struct GeneralConfig {
-    #[serde(default)]
+    #[serde(default = "super::general_impl::default_data_path")]
     pub data_path: Option<PathBuf>,
     /// JSON state file for runtime per-user quota consumption.
     #[serde(default = "default_quota_state_path")]
