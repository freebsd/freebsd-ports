--- vendor/github.com/elastic/elastic-agent-autodiscover/docker/watcher.go.orig	2026-03-16 23:13:35 UTC
+++ vendor/github.com/elastic/elastic-agent-autodiscover/docker/watcher.go
@@ -15,8 +15,8 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
-// +build linux darwin windows
+//go:build linux || darwin || windows || freebsd
+// +build linux darwin windows freebsd
 
 package docker
 
