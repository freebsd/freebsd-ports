-- Avoid assertions in the end of the process due to incorrect onnxruntime
-- un-initialization order.
-- Other distros have the same problem.

--- src/main.rs.orig	2026-04-24 10:28:49 UTC
+++ src/main.rs
@@ -157,12 +157,40 @@ struct Experimental {
     parallel_execution: Option<bool>,
 }
 
+// 1. Declare the raw Unix system call directly so we don't need the external libc crate
+extern "C" {
+    fn _exit(status: i32) -> !;
+}
+
 #[tokio::main]
 async fn main() -> Result<()> {
     let mut tasks = JoinSet::new();
     let result = start(&mut tasks).await;
     while tasks.join_next().await.is_some() {}
-    result
+    
+    // 2. Flush standard streams to ensure all printed results hit the terminal
+    use std::io::Write;
+    let _ = std::io::stdout().flush();
+    let _ = std::io::stderr().flush();
+
+    // 3. Determine the correct status code based on execution success
+    let code = match result {
+        Ok(_) => 0,
+        Err(e) => {
+            eprintln!("Error: {:?}", e);
+            1
+        }
+    };
+
+    // 4. Invoke the raw kernel-level exit. This drops the process image instantly,
+    // preventing the broken C++ ONNX static destructors from ever running.
+    unsafe {
+        _exit(code);
+    }
+
+    // 5. Satisfy the compiler's expected return type contract
+    #[allow(unreachable_code)]
+    Ok(())
 }
 
 async fn start(tasks: &mut JoinSet<()>) -> Result<()> {
