--- vendor/go.opentelemetry.io/otel/sdk/resource/host_id_readfile.go.orig	2023-05-20 05:42:17 UTC
+++ vendor/go.opentelemetry.io/otel/sdk/resource/host_id_readfile.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build bsd || linux
+//go:build darwin || dragonfly || freebsd || netbsd || openbsd || solaris
 
 package resource // import "go.opentelemetry.io/otel/sdk/resource"
 
