--- build.rs.orig	2025-10-08 22:59:16 UTC
+++ build.rs
@@ -50,6 +50,11 @@ fn detect_nginx_features() {
     if let Ok(os) = env::var("DEP_NGINX_OS") {
         println!("cargo::rustc-cfg=ngx_os=\"{os}\"");
     }
+    // Read nginx name detected by nginx-sys and pass to the compiler.
+    println!("cargo::rerun-if-env-changed=DEP_NGINX_NAME");
+    if let Ok(ngx_name) = env::var("DEP_NGINX_NAME") {
+        println!("cargo::rustc-cfg=ngx_name=\"{ngx_name}\"");
+    }
 
     // Generate cfg values for version checks
 
@@ -58,13 +63,16 @@ fn detect_nginx_features() {
     println!("cargo::rerun-if-env-changed=DEP_NGINX_VERSION_NUMBER");
     if let Ok(version) = env::var("DEP_NGINX_VERSION_NUMBER") {
         let version: u64 = version.parse().unwrap();
+        let ngx_name: String = env::var("DEP_NGINX_NAME").unwrap_or("any()".to_string());
 
-        if version >= 1_027_002 {
-            println!("cargo::rustc-cfg=ngx_ssl_cache");
-        }
-
-        if version >= 1_029_002 {
-            println!("cargo::rustc-cfg=ngx_ssl_client_hello_cb");
+        if ngx_name != "freenginx" {
+            if version >= 1_027_002 {
+                println!("cargo::rustc-cfg=ngx_ssl_cache");
+            }
+    
+            if version >= 1_029_002 {
+                println!("cargo::rustc-cfg=ngx_ssl_client_hello_cb");
+            }
         }
     }
 }
