--- cargo-crates/nginx-sys-0.5.0/build/main.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/nginx-sys-0.5.0/build/main.rs
@@ -364,6 +364,8 @@ pub fn print_cargo_metadata<T: AsRef<Path>>(
 
         if name == "nginx_build" {
             println!("cargo::metadata=build={}", unquote(value));
+        } else if name == "nginx_name" {
+            println!("cargo::metadata=name={}", unquote(value));
         } else if name == "nginx_version" {
             println!("cargo::metadata=version={}", unquote(value));
         } else if name == "nginx_version_number" {
@@ -453,6 +455,7 @@ RUST_CONF_NGINX_BUILD=NGINX_VER_BUILD
 #endif
 
 RUST_CONF_NGINX_BUILD=NGINX_VER_BUILD
+RUST_CONF_NGINX_NAME=NGINX_NAME
 RUST_CONF_NGINX_VERSION=NGINX_VER
 RUST_CONF_NGINX_VERSION_NUMBER=nginx_version
 "
