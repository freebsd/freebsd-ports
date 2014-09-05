--- fileinfo_freebsd.go.orig	1970-01-01 02:00:00.000000000 +0200
+++ fileinfo_freebsd.go		2014-08-15 15:55:47.824555519 +0300
@@ -0,0 +1,11 @@
+package main
+
+import (
+  "os"
+  "syscall"
+)
+
+func file_ids(info *os.FileInfo) (uint32, uint32) {
+  fstat := (*(info)).Sys().(*syscall.Stat_t)
+  return fstat.Ino, fstat.Dev
+}
