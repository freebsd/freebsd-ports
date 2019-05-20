--- fileinfo_freebsd.go.orig	2015-06-23 08:32:46 UTC
+++ fileinfo_freebsd.go
@@ -0,0 +1,11 @@
+package main
+
+import (
+  "os"
+  "syscall"
+)
+
+func file_ids(info *os.FileInfo) (uint64, uint64) {
+  fstat := (*(info)).Sys().(*syscall.Stat_t)
+  return fstat.Ino, fstat.Dev
+}
