--- src/providers/data_provider_fo.c.orig	2023-05-25 06:28:15 UTC
+++ src/providers/data_provider_fo.c
@@ -19,6 +19,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/param.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 #include "providers/backend.h"
@@ -237,7 +238,7 @@ errno_t be_fo_set_dns_srv_lookup_plugin(struct be_ctx 
                                         const char *hostname)
 {
     struct fo_resolve_srv_dns_ctx *srv_ctx = NULL;
-    char resolved_hostname[HOST_NAME_MAX + 1];
+    char resolved_hostname[MAXHOSTNAMELEN + 1];
     errno_t ret;
 
     if (hostname == NULL) {
@@ -248,7 +249,7 @@ errno_t be_fo_set_dns_srv_lookup_plugin(struct be_ctx 
                   "gethostname() failed: [%d]: %s\n", ret, strerror(ret));
             return ret;
         }
-        resolved_hostname[HOST_NAME_MAX] = '\0';
+        resolved_hostname[MAXHOSTNAMELEN] = '\0';
         hostname = resolved_hostname;
     }
 
