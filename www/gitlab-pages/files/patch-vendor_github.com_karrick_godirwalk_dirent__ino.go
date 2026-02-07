--- vendor/github.com/karrick/godirwalk/dirent_ino.go.orig	2018-05-19 02:10:07 UTC
+++ vendor/github.com/karrick/godirwalk/dirent_ino.go
@@ -0,0 +1,9 @@
+// +build darwin linux
+
+package godirwalk
+
+import "syscall"
+
+func direntIno(de *syscall.Dirent) uint64 {
+	return de.Ino
+}
