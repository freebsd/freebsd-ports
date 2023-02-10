--- runtime/ops/os/mod.rs.orig	2023-01-13 13:12:37.650775000 +0100
+++ runtime/ops/os/mod.rs	2023-01-13 13:44:03.854517000 +0100
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
