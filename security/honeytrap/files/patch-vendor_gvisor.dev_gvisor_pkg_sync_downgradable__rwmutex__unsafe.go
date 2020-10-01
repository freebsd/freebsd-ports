--- vendor/gvisor.dev/gvisor/pkg/sync/downgradable_rwmutex_unsafe.go.orig	2020-08-27 10:03:50 UTC
+++ vendor/gvisor.dev/gvisor/pkg/sync/downgradable_rwmutex_unsafe.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 
 // +build go1.13
-// +build !go1.15
+// +build !go1.16
 
 // Check go:linkname function signatures when updating Go version.
 
