--- cargo-crates/cranelift-codegen-0.116.1/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/cranelift-codegen-0.116.1/build.rs
@@ -53,9 +53,10 @@ fn main() {
     if isas.is_empty() || host_isa {
         // Try to match native target.
         let target_name = target_triple.split('-').next().unwrap();
-        let isa = meta::isa_from_arch(&target_name).expect("error when identifying target");
-        println!("cargo:rustc-cfg=feature=\"{isa}\"");
-        isas.push(isa);
+        if let Ok(isa) = meta::isa_from_arch(&target_name) {
+            println!("cargo:rustc-cfg=feature=\"{isa}\"");
+            isas.push(isa);
+        }
     }
 
     let cur_dir = env::current_dir().expect("Can't access current working directory");
