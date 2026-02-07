--- ../boring-signal-v4.18.0/boring-sys/build/main.rs.orig	2024-04-27 16:40:34 UTC
+++ ../boring-signal-v4.18.0/boring-sys/build/main.rs
@@ -478,9 +478,9 @@ fn ensure_patches_applied(config: &Config) -> io::Resu
     lock_file.lock()?;
 
     // NOTE: init git in the copied files, so we can apply patches
-    if !has_git {
-        run_command(Command::new("git").arg("init").current_dir(src_path))?;
-    }
+//    if !has_git {
+//        run_command(Command::new("git").arg("init").current_dir(src_path))?;
+//    }
 
     if config.features.pq_experimental {
         println!("cargo:warning=applying experimental post quantum crypto patch to boringssl");
@@ -520,8 +520,8 @@ fn apply_patch(config: &Config, patch_name: &str) -> i
     }
 
     run_command(
-        Command::new("git")
-            .args(&args)
+        Command::new("patch")
+            .args(["-p 1"])
             .arg(cmd_path)
             .current_dir(src_path),
     )?;
@@ -650,6 +650,7 @@ fn get_cpp_runtime_lib(config: &Config) -> Option<Stri
     if env::var_os("CARGO_CFG_UNIX").is_some() {
         match env::var("CARGO_CFG_TARGET_OS").unwrap().as_ref() {
             "macos" | "ios" => Some("c++".into()),
+            "freebsd" => Some("c++".into()),
             _ => Some("stdc++".into()),
         }
     } else {
