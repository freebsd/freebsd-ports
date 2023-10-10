--- ntpd/src/daemon/config/mod.rs.orig	2023-07-28 13:42:06 UTC
+++ ntpd/src/daemon/config/mod.rs
@@ -272,7 +272,7 @@ impl Config {
         }
 
         // for the global file we also ignore it when there are permission errors
-        let global_path = Path::new("/etc/ntpd-rs/ntp.toml");
+        let global_path = Path::new("%%ETCDIR%%/ntp.toml");
         if global_path.exists() {
             info!("using config file at default location `{:?}`", global_path);
             match Config::from_file(global_path).await {
