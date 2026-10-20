--- src/maestro/mod.rs.orig	2026-10-05 08:27:50 UTC
+++ src/maestro/mod.rs
@@ -100,7 +100,11 @@ async fn run_inner(
             daemon_opts.pid_file_path(),
             daemon_opts.strict_runtime_paths,
         );
-        if let Err(e) = pf.acquire() {
+        let acquired = match daemon_opts.user.as_deref() {
+            Some(user) => pf.acquire_for_user(Some(user)),
+            None => pf.acquire(),
+        };
+        if let Err(e) = acquired {
             eprintln!("[telemt] {}", e);
             std::process::exit(1);
         }
