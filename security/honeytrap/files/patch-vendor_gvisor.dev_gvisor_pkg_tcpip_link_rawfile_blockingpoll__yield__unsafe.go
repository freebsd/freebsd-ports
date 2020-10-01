--- vendor/gvisor.dev/gvisor/pkg/tcpip/link/rawfile/blockingpoll_yield_unsafe.go.orig	2020-08-27 10:08:00 UTC
+++ vendor/gvisor.dev/gvisor/pkg/tcpip/link/rawfile/blockingpoll_yield_unsafe.go
@@ -14,7 +14,7 @@
 
 // +build linux,amd64 linux,arm64
 // +build go1.12
-// +build !go1.15
+// +build !go1.16
 
 // Check go:linkname function signatures when updating Go version.
 
