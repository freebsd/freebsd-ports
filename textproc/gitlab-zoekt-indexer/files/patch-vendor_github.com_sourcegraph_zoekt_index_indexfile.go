--- vendor/github.com/sourcegraph/zoekt/index/indexfile.go.orig	2025-07-16 16:01:58 UTC
+++ vendor/github.com/sourcegraph/zoekt/index/indexfile.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build linux || darwin
+//go:build linux || darwin || freebsd
 
 package index
 
