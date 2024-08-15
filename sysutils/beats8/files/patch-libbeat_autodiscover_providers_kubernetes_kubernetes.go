--- libbeat/autodiscover/providers/kubernetes/kubernetes.go.orig	2024-07-13 21:44:01.984103000 +0200
+++ libbeat/autodiscover/providers/kubernetes/kubernetes.go	2024-07-13 21:44:07.633470000 +0200
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package kubernetes
 
