--- src/providers/ipa/ipa_common.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ipa/ipa_common.c
@@ -22,6 +22,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/param.h>
 #include <netdb.h>
 #include <ctype.h>
 #include <arpa/inet.h>
@@ -51,7 +52,7 @@ int ipa_get_options(TALLOC_CTX *memctx,
     char *realm;
     char *ipa_hostname;
     int ret;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[MAXHOSTNAMELEN + 1];
 
     opts = talloc_zero(memctx, struct ipa_options);
     if (!opts) return ENOMEM;
@@ -88,7 +89,7 @@ int ipa_get_options(TALLOC_CTX *memctx,
                       strerror(ret));
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[MAXHOSTNAMELEN] = '\0';
         DEBUG(SSSDBG_TRACE_ALL, "Setting ipa_hostname to [%s].\n", hostname);
         ret = dp_opt_set_string(opts->basic, IPA_HOSTNAME, hostname);
         if (ret != EOK) {
