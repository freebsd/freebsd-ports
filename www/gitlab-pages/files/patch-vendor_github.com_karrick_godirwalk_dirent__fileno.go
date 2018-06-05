--- vendor/github.com/karrick/godirwalk/dirent_fileno.go.orig	2018-05-19 02:10:07 UTC
+++ vendor/github.com/karrick/godirwalk/dirent_fileno.go
@@ -0,0 +1,9 @@
+// +build dragonfly freebsd openbsd netbsd
+
+package godirwalk
+
+import "syscall"
+
+func direntIno(de *syscall.Dirent) uint64 {
+	return uint64(de.Fileno)
+}
