--- src/providers/ldap/sdap_async_sudo_hostinfo.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ldap/sdap_async_sudo_hostinfo.c
@@ -18,6 +18,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/param.h>
 #include <errno.h>
 #include <tevent.h>
 #include <talloc.h>
@@ -357,7 +358,7 @@ static struct tevent_req *sdap_sudo_get_hostnames_send
     struct tevent_req *subreq = NULL;
     struct sdap_sudo_get_hostnames_state *state = NULL;
     char *dot = NULL;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[MAXHOSTNAMELEN + 1];
     int ret;
 
     req = tevent_req_create(mem_ctx, &state,
@@ -387,7 +388,7 @@ static struct tevent_req *sdap_sudo_get_hostnames_send
                                     "[%d]: %s\n", ret, strerror(ret));
         goto done;
     }
-    hostname[HOST_NAME_MAX] = '\0';
+    hostname[MAXHOSTNAMELEN] = '\0';
 
     state->hostnames[0] = talloc_strdup(state->hostnames, hostname);
     if (state->hostnames[0] == NULL) {
