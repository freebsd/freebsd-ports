--- vendor/gvisor.dev/gvisor/pkg/sync/tmutex_unsafe.go.orig	2020-01-31 23:11:21 UTC
+++ vendor/gvisor.dev/gvisor/pkg/sync/tmutex_unsafe.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 
 // +build go1.13
-// +build !go1.15
+// +build !go1.17
 
 // When updating the build constraint (above), check that syncMutex matches the
 // standard library sync.Mutex definition.
