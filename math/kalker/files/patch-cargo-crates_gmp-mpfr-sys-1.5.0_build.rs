--- cargo-crates/gmp-mpfr-sys-1.5.0/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/gmp-mpfr-sys-1.5.0/build.rs
@@ -40,8 +40,8 @@ const MPC_DIR: &str = "mpc-1.3.1-c";
 const GMP_DIR: &str = "gmp-6.2.1-c";
 const MPFR_DIR: &str = "mpfr-4.2.0-c";
 const MPC_DIR: &str = "mpc-1.3.1-c";
-const GMP_VER: (i32, i32, i32) = (6, 2, 1);
-const MPFR_VER: (i32, i32, i32) = (4, 2, 0);
+const GMP_VER: (i32, i32, i32) = (6, 3, 0);
+const MPFR_VER: (i32, i32, i32) = (4, 2, 1);
 const MPC_VER: (i32, i32, i32) = (1, 3, 1);
 
 #[derive(Clone, Copy, PartialEq)]
@@ -194,7 +194,7 @@ fn check_system_libs(env: &Environment) {
 
     let mut cmd = Command::new(&env.c_compiler);
     cmd.current_dir(&try_dir)
-        .args(["-fPIC", "system_gmp.c", "-lgmp", "-o", "system_gmp.exe"]);
+        .args(["-fPIC", "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include", "system_gmp.c", "-lgmp", "-o", "system_gmp.exe"]);
     execute(cmd);
 
     cmd = Command::new(try_dir.join("system_gmp.exe"));
@@ -218,6 +218,7 @@ fn check_system_libs(env: &Environment) {
         cmd.current_dir(&try_dir).args([
             "-fPIC",
             "system_mpfr.c",
+            "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include",
             "-lmpfr",
             "-lgmp",
             "-o",
@@ -243,6 +244,7 @@ fn check_system_libs(env: &Environment) {
         cmd = Command::new(&env.c_compiler);
         cmd.current_dir(&try_dir).args([
             "-fPIC",
+            "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include",
             "system_mpc.c",
             "-lmpc",
             "-lgmp",
@@ -975,7 +977,7 @@ fn write_link_info(env: &Environment, feature_mpfr: bo
     println!("cargo:out_dir={out_str}");
     println!("cargo:lib_dir={lib_str}");
     println!("cargo:include_dir={include_str}");
-    println!("cargo:rustc-link-search=native={lib_str}");
+    println!("cargo:rustc-link-search=native={}/lib", "%%LOCALBASE%%");
 
     let target_env = env::var("CARGO_CFG_TARGET_ENV").unwrap_or_default();
     if target_env == "musl" && env.use_system_libs {
