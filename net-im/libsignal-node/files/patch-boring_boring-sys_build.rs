--- ../boring-8245063ae6eb97d909982b89fad45bb7f0a2a1a0/boring-sys/build.rs.orig	2024-01-05 10:45:46 UTC
+++ ../boring-8245063ae6eb97d909982b89fad45bb7f0a2a1a0/boring-sys/build.rs
@@ -456,9 +456,9 @@ fn ensure_patches_applied() -> io::Result<()> {
     lock_file.lock()?;
 
     // NOTE: init git in the copied files, so we can apply patches
-    if !has_git {
-        run_command(Command::new("git").args(["init"]).current_dir(&src_path))?;
-    }
+//    if !has_git {
+//        run_command(Command::new("git").args(["init"]).current_dir(&src_path))?;
+//    }
 
     if cfg!(feature = "pq-experimental") {
         println!("cargo:warning=applying experimental post quantum crypto patch to boringssl");
@@ -482,11 +482,9 @@ fn apply_patch(patch_name: &str) -> io::Result<()> {
         .canonicalize()?;
 
     run_command(
-        Command::new("git")
+        Command::new("patch")
             .args([
-                "apply",
-                "-v",
-                "--whitespace=fix",
+		"-p 1",
                 &cmd_path.display().to_string(),
             ])
             .current_dir(src_path),
