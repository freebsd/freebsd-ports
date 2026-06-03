--- libbeat/autodiscover/providers/kubernetes/config.go.orig	2026-02-23 21:59:26 UTC
+++ libbeat/autodiscover/providers/kubernetes/config.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package kubernetes
 
