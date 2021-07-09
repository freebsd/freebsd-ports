--- tensorflow/core/platform/cloud/gcs_dns_cache.cc.orig	2019-10-14 21:08:43 UTC
+++ tensorflow/core/platform/cloud/gcs_dns_cache.cc
@@ -26,6 +26,11 @@ limitations under the License.
 #endif
 #include <sys/types.h>
 
+#ifdef __FreeBSD__ 
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 namespace tensorflow {
 
 namespace {
