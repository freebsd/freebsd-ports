--- pkg/autodiscover/docker/client_test.go.orig	2026-09-09 20:15:21 UTC
+++ pkg/autodiscover/docker/client_test.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build integration && (linux || darwin || windows)
+//go:build integration && (linux || darwin || windows || freebsd)
 
 package docker
 
