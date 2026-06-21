-- FreeBSD is not Linux, but PaddlePaddle source defines _LINUX for any
-- platform that is not Windows or macOS (using '#if defined _WIN32 || defined
-- __APPLE__'). This causes Linux-only code (stdio_ext.h includes, glibc-specific
-- syscalls) to be compiled on FreeBSD. Add __FreeBSD__ to the exclusion list.
--- paddle/fluid/framework/data_feed.cu.orig	2026-06-19 18:10:22 UTC
+++ paddle/fluid/framework/data_feed.cu
@@ -11,7 +11,7 @@ limitations under the License. */
 See the License for the specific language governing permissions and
 limitations under the License. */
 
-#if defined _WIN32 || defined __APPLE__
+#if defined _WIN32 || defined __APPLE__ || defined __FreeBSD__
 #else
 #define _LINUX
 #endif
