--- vendor/go.opentelemetry.io/otel/sdk/resource/host_id_exec.go.orig	2023-05-20 05:42:01 UTC
+++ vendor/go.opentelemetry.io/otel/sdk/resource/host_id_exec.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build bsd || darwin
+//go:build darwin || dragonfly || freebsd || netbsd || openbsd || solaris
 
 package resource // import "go.opentelemetry.io/otel/sdk/resource"
 
