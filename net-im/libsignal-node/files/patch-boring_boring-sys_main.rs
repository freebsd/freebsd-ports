--- ../boring-signal-v4.6.0/boring-sys/build/main.rs.orig	2024-04-27 16:40:34.000626000 +0200
+++ ../boring-signal-v4.6.0/boring-sys/build/main.rs	2024-04-27 17:41:33.228588000 +0200
@@ -477,9 +477,9 @@ fn ensure_patches_applied(config: &Config) -> io::Resu
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
@@ -515,8 +515,8 @@ fn apply_patch(config: &Config, patch_name: &str) -> i
     }
 
     run_command(
-        Command::new("git")
-            .args(&args)
+        Command::new("patch")
+            .args(["-p 1"])
             .arg(cmd_path)
             .current_dir(src_path),
     )?;
