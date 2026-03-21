--- libbeat/autodiscover/providers/docker/config.go.orig	2025-09-15 19:57:17 UTC
+++ libbeat/autodiscover/providers/docker/config.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package docker
 
