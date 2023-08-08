--- libbeat/autodiscover/providers/docker/config.go.orig	2022-10-24 06:49:31 UTC
+++ libbeat/autodiscover/providers/docker/config.go
@@ -15,8 +15,8 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
-// +build linux darwin windows
+//go:build linux || darwin || windows || freebsd
+// +build linux darwin windows freebsd
 
 package docker
 
