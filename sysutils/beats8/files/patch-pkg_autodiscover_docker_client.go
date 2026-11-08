--- pkg/autodiscover/docker/client.go.orig	2026-08-26 15:33:57 UTC
+++ pkg/autodiscover/docker/client.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package docker
 
