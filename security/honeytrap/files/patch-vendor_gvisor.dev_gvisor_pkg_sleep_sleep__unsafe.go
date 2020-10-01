--- vendor/gvisor.dev/gvisor/pkg/sleep/sleep_unsafe.go.orig	2020-08-27 10:03:23 UTC
+++ vendor/gvisor.dev/gvisor/pkg/sleep/sleep_unsafe.go
@@ -13,7 +13,7 @@
 // limitations under the License.
 
 // +build go1.11
-// +build !go1.15
+// +build !go1.16
 
 // Check go:linkname function signatures when updating Go version.
 
