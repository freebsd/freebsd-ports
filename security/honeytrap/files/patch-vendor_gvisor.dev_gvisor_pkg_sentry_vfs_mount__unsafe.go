--- vendor/gvisor.dev/gvisor/pkg/sentry/vfs/mount_unsafe.go.orig	2020-08-27 10:09:46 UTC
+++ vendor/gvisor.dev/gvisor/pkg/sentry/vfs/mount_unsafe.go
@@ -13,7 +13,7 @@
 // limitations under the License.
 
 // +build go1.12
-// +build !go1.15
+// +build !go1.16
 
 // Check go:linkname function signatures when updating Go version.
 
