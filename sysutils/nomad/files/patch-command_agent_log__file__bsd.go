--- command/agent/log_file_bsd.go.orig	2021-11-24 18:54:06 UTC
+++ command/agent/log_file_bsd.go
@@ -1,4 +1,5 @@
-//go:build darwin || freebsd || netbsd || openbsd
+//go:build !386 && (darwin || freebsd || netbsd || openbsd)
+// +build !386
 // +build darwin freebsd netbsd openbsd
 
 package agent
