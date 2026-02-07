--- src/kerberosbasic.h.orig	2015-03-29 03:39:10 UTC
+++ src/kerberosbasic.h
@@ -14,8 +14,8 @@
  * limitations under the License.
  **/
 
+#include <krb5.h>
 #include <gssapi/gssapi.h>
-#include <gssapi/gssapi_generic.h>
 #include <gssapi/gssapi_krb5.h>
 
 #define krb5_get_err_text(context,code) error_message(code)
