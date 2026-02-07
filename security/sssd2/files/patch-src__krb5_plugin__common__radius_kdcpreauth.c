--- src/krb5_plugin/common/radius_kdcpreauth.c.orig	2023-05-05 08:11:07 UTC
+++ src/krb5_plugin/common/radius_kdcpreauth.c
@@ -18,6 +18,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/param.h>
 #include <errno.h>
 #include <stdbool.h>
 #include <stdlib.h>
@@ -414,7 +415,7 @@ sss_radiuskdc_client_init(krb5_context kctx,
                           struct sss_radiuskdc_config *config)
 {
     struct sss_radiuskdc_client *client;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[MAXHOSTNAMELEN + 1];
     krb5_data data = {0};
     krb5_error_code ret;
 
