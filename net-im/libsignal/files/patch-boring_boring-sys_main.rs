--- ../boring-signal-v5.2.0/boring-sys/build/main.rs.orig	2026-09-10 13:23:33.640782000 -0400
+++ ../boring-signal-v5.2.0/boring-sys/build/main.rs	2026-09-10 13:25:13.915284000 -0400
@@ -487,9 +487,9 @@
     lock_file.lock()?;
 
     // NOTE: init git in the copied files, so we can apply patches
-    if !has_git {
-        run_command(Command::new("git").arg("init").current_dir(src_path))?;
-    }
+//    if !has_git {
+//        run_command(Command::new("git").arg("init").current_dir(src_path))?;
+//    }
 
     if config.features.allow_crl_extensions_bad_version {
         println!(
@@ -540,8 +540,8 @@
     }
 
     run_command(
-        Command::new("git")
-            .args(&args)
+        Command::new("patch")
+            .args(["-p 1"])
             .arg(cmd_path)
             .current_dir(src_path),
     )?;
