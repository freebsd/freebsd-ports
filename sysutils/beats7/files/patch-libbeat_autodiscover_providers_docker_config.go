--- libbeat/autodiscover/providers/docker/config.go.orig	2021-07-04 13:44:36 UTC
+++ libbeat/autodiscover/providers/docker/config.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-// +build linux darwin windows
+// +build linux darwin windows freebsd
 
 package docker
 
