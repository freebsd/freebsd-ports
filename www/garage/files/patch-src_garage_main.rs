--- src/garage/main.rs.orig	2022-02-08 20:27:47 UTC
+++ src/garage/main.rs
@@ -67,7 +67,9 @@ async fn main() {
 			// Abort on panic (same behavior as in Go)
 			std::panic::set_hook(Box::new(|panic_info| {
 				error!("{}", panic_info.to_string());
-				std::process::abort();
+                std::process::exit(1);
+                // On FreeBSD it dumps core:
+				// std::process::abort();
 			}));
 
 			server::run_server(opt.config_file).await
