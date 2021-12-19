--- libbeat/common/docker/client.go.orig	2021-12-17 15:54:41 UTC
+++ libbeat/common/docker/client.go
@@ -15,8 +15,8 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
-// +build linux darwin windows
+//go:build linux || darwin || windows || freebsd
+// +build linux darwin windows freebsd
 
 package docker
 
