--- src/providers/ad/ad_common.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ad/ad_common.c
@@ -19,6 +19,7 @@
     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
+#include <sys/param.h>
 #include <ctype.h>
 
 #include "providers/ad/ad_common.h"
@@ -495,8 +496,8 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
     char *server;
     char *realm;
     char *ad_hostname;
-    char hostname[HOST_NAME_MAX + 1];
-    char fqdn[HOST_NAME_MAX + 1];
+    char hostname[MAXHOSTNAMELEN + 1];
+    char fqdn[MAXHOSTNAMELEN + 1];
     char *case_sensitive_opt;
     const char *opt_override;
 
@@ -543,7 +544,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
                    strerror(ret));
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[MAXHOSTNAMELEN] = '\0';
 
         if (strchr(hostname, '.') == NULL) {
             ret = ad_try_to_get_fqdn(hostname, fqdn, sizeof(fqdn));
@@ -552,8 +553,8 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
                       "The hostname [%s] has been expanded to FQDN [%s]. "
                       "If sssd should really use the short hostname, please "
                       "set ad_hostname explicitly.\n", hostname, fqdn);
-                strncpy(hostname, fqdn, HOST_NAME_MAX);
-                hostname[HOST_NAME_MAX] = '\0';
+                strncpy(hostname, fqdn, MAXHOSTNAMELEN);
+                hostname[MAXHOSTNAMELEN] = '\0';
             }
         }
 
