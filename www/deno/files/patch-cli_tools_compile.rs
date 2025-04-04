--- cli/tools/compile.rs.orig	2025-04-01 12:15:22 UTC
+++ cli/tools/compile.rs
@@ -492,6 +492,32 @@ mod test {
   }
 
   #[tokio::test]
+  async fn resolve_compile_executable_output_path_target_freebsd() {
+    let http_client = HttpClientProvider::new(None, None);
+    let path = resolve_compile_executable_output_path(
+      &http_client,
+      &CompileFlags {
+        source_file: "mod.ts".to_string(),
+        output: Some(String::from("./file")),
+        args: Vec::new(),
+        target: Some("x86_64-unknown-freebsd".to_string()),
+        no_terminal: false,
+        icon: None,
+        include: vec![],
+        eszip: true,
+      },
+      &std::env::current_dir().unwrap(),
+    )
+    .await
+    .unwrap();
+
+    // no extension, no matter what the operating system is
+    // because the target was specified as freebsd
+    // https://github.com/denoland/deno/issues/9667
+    assert_eq!(path.file_name().unwrap(), "file");
+  }
+
+  #[tokio::test]
   async fn resolve_compile_executable_output_path_target_windows() {
     let http_client = HttpClientProvider::new(None, None);
     let path = resolve_compile_executable_output_path(
