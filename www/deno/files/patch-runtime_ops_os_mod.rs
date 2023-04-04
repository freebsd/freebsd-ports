--- runtime/ops/os/mod.rs.orig	2023-01-13 13:12:37 UTC
+++ runtime/ops/os/mod.rs
@@ -399,6 +399,11 @@ fn rss() -> usize {
   task_info.resident_size as usize
 }
 
+#[cfg(target_os = "freebsd")]
+fn rss() -> usize {
+  0
+}
+
 #[cfg(windows)]
 fn rss() -> usize {
   use winapi::shared::minwindef::DWORD;
