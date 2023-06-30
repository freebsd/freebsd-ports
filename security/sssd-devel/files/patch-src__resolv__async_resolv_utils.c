--- src/resolv/async_resolv_utils.c.orig	2023-05-05 08:11:07 UTC
+++ src/resolv/async_resolv_utils.c
@@ -18,6 +18,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/param.h>
 #include <string.h>
 #include <talloc.h>
 #include <tevent.h>
@@ -45,7 +46,7 @@ resolv_get_domain_send(TALLOC_CTX *mem_ctx,
     struct resolv_get_domain_state *state = NULL;
     struct tevent_req *req = NULL;
     struct tevent_req *subreq = NULL;
-    char system_hostname[HOST_NAME_MAX + 1];
+    char system_hostname[MAXHOSTNAMELEN + 1];
     errno_t ret;
 
     req = tevent_req_create(mem_ctx, &state,
@@ -64,7 +65,7 @@ resolv_get_domain_send(TALLOC_CTX *mem_ctx,
                                         ret, strerror(ret));
             goto immediately;
         }
-        system_hostname[HOST_NAME_MAX] = '\0';
+        system_hostname[MAXHOSTNAMELEN] = '\0';
         hostname = system_hostname;
     }
 
