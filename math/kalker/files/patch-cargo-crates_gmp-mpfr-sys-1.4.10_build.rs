--- cargo-crates/gmp-mpfr-sys-1.4.10/build.rs.orig	2022-11-10 13:33:20 UTC
+++ cargo-crates/gmp-mpfr-sys-1.4.10/build.rs
@@ -212,7 +212,7 @@ fn check_system_libs(env: &Environment) {
 
     let mut cmd = Command::new(&env.c_compiler);
     cmd.current_dir(&try_dir)
-        .args(&["-fPIC", "system_gmp.c", "-lgmp", "-o", "system_gmp.exe"]);
+        .args(&["-fPIC", "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include", "system_gmp.c", "-lgmp", "-o", "system_gmp.exe"]);
     execute(cmd);
 
     cmd = Command::new(try_dir.join("system_gmp.exe"));
@@ -236,6 +236,7 @@ fn check_system_libs(env: &Environment) {
         cmd.current_dir(&try_dir).args(&[
             "-fPIC",
             "system_mpfr.c",
+            "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include",
             "-lmpfr",
             "-lgmp",
             "-o",
@@ -261,6 +262,7 @@ fn check_system_libs(env: &Environment) {
         cmd = Command::new(&env.c_compiler);
         cmd.current_dir(&try_dir).args(&[
             "-fPIC",
+            "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include",
             "system_mpc.c",
             "-lmpc",
             "-lgmp",
@@ -1013,7 +1015,7 @@ fn write_link_info(env: &Environment, feature_mpfr: bo
     println!("cargo:out_dir={}", out_str);
     println!("cargo:lib_dir={}", lib_str);
     println!("cargo:include_dir={}", include_str);
-    println!("cargo:rustc-link-search=native={}", lib_str);
+    println!("cargo:rustc-link-search=native={}/lib", "%%LOCALBASE%%");
 
     let target_env = env::var("CARGO_CFG_TARGET_ENV").unwrap_or_default();
     if target_env == "musl" && env.use_system_libs {
