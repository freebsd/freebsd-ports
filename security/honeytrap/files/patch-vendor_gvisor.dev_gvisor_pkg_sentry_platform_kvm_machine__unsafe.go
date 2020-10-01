--- vendor/gvisor.dev/gvisor/pkg/sentry/platform/kvm/machine_unsafe.go.orig	2020-08-27 10:11:57 UTC
+++ vendor/gvisor.dev/gvisor/pkg/sentry/platform/kvm/machine_unsafe.go
@@ -13,7 +13,7 @@
 // limitations under the License.
 
 // +build go1.12
-// +build !go1.15
+// +build !go1.16
 
 // Check go:linkname function signatures when updating Go version.
 
