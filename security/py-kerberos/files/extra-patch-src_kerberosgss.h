--- src/kerberosgss.h.orig	2015-03-29 03:41:32 UTC
+++ src/kerberosgss.h
@@ -14,8 +14,9 @@
  * limitations under the License.
  **/
 
+#include <krb5.h>
+#define gss_krb5_nt_service_name GSS_KRB5_NT_PRINCIPAL_NAME
 #include <gssapi/gssapi.h>
-#include <gssapi/gssapi_generic.h>
 #include <gssapi/gssapi_krb5.h>
 
 #define krb5_get_err_text(context,code) error_message(code)
