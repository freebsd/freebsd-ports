--- ntp-metrics-exporter/src/lib.rs.orig	2023-07-28 10:29:42 UTC
+++ ntp-metrics-exporter/src/lib.rs
@@ -48,7 +48,7 @@ pub async fn main() -> Result<(), Box<dyn std::error::
         Some(path) => path,
         None => match config.observe.path {
             Some(path) => path,
-            None => "/run/ntpd-rs/observe".into(),
+            None => "/var/run/ntpd-rs/observe".into(),
         },
     };
 
