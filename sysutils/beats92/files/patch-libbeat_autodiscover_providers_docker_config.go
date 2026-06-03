--- libbeat/autodiscover/providers/docker/config.go.orig	2026-02-23 21:59:03 UTC
+++ libbeat/autodiscover/providers/docker/config.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package docker
 
