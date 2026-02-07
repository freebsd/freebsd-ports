--- libbeat/autodiscover/providers/kubernetes/config.go.orig	2024-07-09 00:00:36.000000000 +0200
+++ libbeat/autodiscover/providers/kubernetes/config.go	2024-07-13 21:42:32.799000000 +0200
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package kubernetes
 
