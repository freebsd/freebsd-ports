--- pkg/autodiscover/docker/watcher.go.orig	2026-09-09 20:15:21 UTC
+++ pkg/autodiscover/docker/watcher.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package docker
 
