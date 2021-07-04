--- libbeat/autodiscover/providers/kubernetes/kubernetes.go.orig	2021-07-04 13:45:12 UTC
+++ libbeat/autodiscover/providers/kubernetes/kubernetes.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-// +build linux darwin windows
+// +build linux darwin windows freebsd
 
 package kubernetes
 
