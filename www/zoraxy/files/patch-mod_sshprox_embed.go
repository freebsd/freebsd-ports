--- mod/sshprox/embed.go.orig	2026-08-19 10:56:14 UTC
+++ mod/sshprox/embed.go
@@ -1,5 +1,5 @@
-//go:build (linux && mipsle) || (linux && riscv64) || (freebsd && amd64) || (darwin && arm64)
-// +build linux,mipsle linux,riscv64 freebsd,amd64 darwin,arm64
+//go:build (linux && mipsle) || (linux && riscv64) || freebsd || (darwin && arm64)
+// +build linux,mipsle linux,riscv64 freebsd darwin,arm64
 
 package sshprox
 
