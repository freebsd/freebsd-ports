--- cargo-crates/gmp-mpfr-sys-1.6.2/build.rs.orig
+++ cargo-crates/gmp-mpfr-sys-1.6.2/build.rs
@@ -195,8 +195,15 @@
     create_file_or_panic(&try_dir.join("system_gmp.c"), SYSTEM_GMP_C);
 
     let mut cmd = Command::new(&env.c_compiler);
-    cmd.current_dir(&try_dir)
-        .args(["-fPIC", "system_gmp.c", "-lgmp", "-o", "system_gmp.exe"]);
+    cmd.current_dir(&try_dir).args([
+        "-fPIC",
+        "-L%%LOCALBASE%%/lib",
+        "-I%%LOCALBASE%%/include",
+        "system_gmp.c",
+        "-lgmp",
+        "-o",
+        "system_gmp.exe",
+    ]);
     execute(cmd);
 
     cmd = Command::new(try_dir.join("system_gmp.exe"));
@@ -220,6 +227,8 @@
         cmd.current_dir(&try_dir).args([
             "-fPIC",
             "system_mpfr.c",
+            "-L%%LOCALBASE%%/lib",
+            "-I%%LOCALBASE%%/include",
             "-lmpfr",
             "-lgmp",
             "-o",
@@ -245,6 +254,8 @@
         cmd = Command::new(&env.c_compiler);
         cmd.current_dir(&try_dir).args([
             "-fPIC",
+            "-L%%LOCALBASE%%/lib",
+            "-I%%LOCALBASE%%/include",
             "system_mpc.c",
             "-lmpc",
             "-lgmp",
@@ -989,7 +1000,7 @@
     println!("cargo:out_dir={out_str}");
     println!("cargo:lib_dir={lib_str}");
     println!("cargo:include_dir={include_str}");
-    println!("cargo:rustc-link-search=native={lib_str}");
+    println!("cargo:rustc-link-search=native={}/lib", "%%LOCALBASE%%");
 
     let target_env = env::var("CARGO_CFG_TARGET_ENV").unwrap_or_default();
     if target_env == "musl" && env.use_system_libs {
