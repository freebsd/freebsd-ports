--- ../gmp-mpfr-sys-21966f4bfb56c87d407eb14c72e92ef4e55856aa/build.rs.orig	2021-10-03 17:55:55 UTC
+++ ../gmp-mpfr-sys-21966f4bfb56c87d407eb14c72e92ef4e55856aa/build.rs
@@ -179,7 +179,7 @@
 
     cmd = Command::new(&env.c_compiler);
     cmd.current_dir(&try_dir)
-        .args(&["-fPIC", "system_gmp.c", "-lgmp", "-o", "system_gmp.exe"]);
+        .args(&["-fPIC", "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include", "system_gmp.c", "-lgmp", "-o", "system_gmp.exe"]);
     execute(cmd);
 
     cmd = Command::new(try_dir.join("system_gmp.exe"));
@@ -202,6 +202,7 @@
         cmd = Command::new(&env.c_compiler);
         cmd.current_dir(&try_dir).args(&[
             "-fPIC",
+            "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include",
             "system_mpfr.c",
             "-lmpfr",
             "-lgmp",
@@ -228,6 +229,7 @@
         cmd = Command::new(&env.c_compiler);
         cmd.current_dir(&try_dir).args(&[
             "-fPIC",
+            "-L%%LOCALBASE%%/lib", "-I%%LOCALBASE%%/include",
             "system_mpc.c",
             "-lmpc",
             "-lgmp",
@@ -974,7 +976,7 @@
     println!("cargo:out_dir={}", out_str);
     println!("cargo:lib_dir={}", lib_str);
     println!("cargo:include_dir={}", include_str);
-    println!("cargo:rustc-link-search=native={}", lib_str);
+    println!("cargo:rustc-link-search=native={}/lib", "%%LOCALBASE%%");
     let maybe_static = if env.use_system_libs { "" } else { "static=" };
     if feature_mpc {
         println!("cargo:rustc-link-lib={}mpc", maybe_static);
