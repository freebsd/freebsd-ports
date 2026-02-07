--- libbeat/autodiscover/providers/docker/config.go.orig	2024-07-09 00:00:36.000000000 +0200
+++ libbeat/autodiscover/providers/docker/config.go	2024-07-13 21:38:12.739090000 +0200
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package docker
 
