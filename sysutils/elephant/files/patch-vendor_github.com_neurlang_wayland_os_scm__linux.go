--- vendor/github.com/neurlang/wayland/os/scm_linux.go.orig	2025-11-14 04:42:08 UTC
+++ vendor/github.com/neurlang/wayland/os/scm_linux.go
@@ -1,5 +1,5 @@
-//go:build aix || darwin || dragonfly || freebsd || linux || netbsd || openbsd || solaris
-// +build aix darwin dragonfly freebsd linux netbsd openbsd solaris
+//go:build aix || darwin || dragonfly || linux || netbsd || openbsd || solaris
+// +build aix darwin dragonfly linux netbsd openbsd solaris
 
 package os
 
