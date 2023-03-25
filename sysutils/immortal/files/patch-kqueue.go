--- kqueue.go.orig	2023-03-25 13:19:35 UTC
+++ kqueue.go
@@ -1,5 +1,5 @@
 // +build freebsd netbsd openbsd dragonfly darwin
-// +build amd64 arm64
+// +build amd64 arm64 riscv64
 
 package immortal
 
