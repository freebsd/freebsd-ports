--- vendor/gvisor.dev/gvisor/pkg/sync/memmove_unsafe.go.orig	2020-01-31 23:11:21 UTC
+++ vendor/gvisor.dev/gvisor/pkg/sync/memmove_unsafe.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 
 // +build go1.12
-// +build !go1.15
+// +build !go1.17
 
 // Check go:linkname function signatures when updating Go version.
 
