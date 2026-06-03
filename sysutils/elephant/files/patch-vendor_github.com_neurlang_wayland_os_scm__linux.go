--- vendor/github.com/neurlang/wayland/os/scm_linux.go.orig	2026-03-30 02:44:23 UTC
+++ vendor/github.com/neurlang/wayland/os/scm_linux.go
@@ -1,5 +1,5 @@
-//go:build aix || dragonfly || freebsd || linux || netbsd || openbsd || solaris
-// +build aix dragonfly freebsd linux netbsd openbsd solaris
+//go:build aix || darwin || dragonfly || linux || netbsd || openbsd || solaris
+// +build aix darwin dragonfly linux netbsd openbsd solaris
 
 package os
 
