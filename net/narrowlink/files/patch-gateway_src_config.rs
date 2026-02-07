--- gateway/src/config.rs.orig	2024-01-02 18:33:38 UTC
+++ gateway/src/config.rs
@@ -139,11 +139,13 @@ impl Config {
         );
         let etc = if cfg!(target_os = "linux") {
             Some(PathBuf::from("/etc/narrowlink/gateway.yaml"))
+        } else if cfg!(target_os = "freebsd") {
+            Some(PathBuf::from("/usr/local/etc/narrowlink/gateway.yaml"))
         } else {
             None
         }
         .filter(|f| f.is_file());
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         trace!(
             "config file in etc dir: {}",
             if etc.is_some() { "found" } else { "not found" }
