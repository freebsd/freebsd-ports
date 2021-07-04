--- libbeat/autodiscover/providers/docker/docker.go.orig	2021-07-04 13:44:49 UTC
+++ libbeat/autodiscover/providers/docker/docker.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-// +build linux darwin windows
+// +build linux darwin windows freebsd
 
 package docker
 
