--- src/kerberos.c.orig	2021-01-09 04:30:38 UTC
+++ src/kerberos.c
@@ -14,6 +14,7 @@
  * limitations under the License.
  **/
 
+#define PY_SSIZE_T_CLEAN
 #include <Python.h>
 
 #include "kerberosbasic.h"
@@ -244,9 +245,9 @@ static PyObject *channelBindings(PyObject *self, PyObj
     char *initiator_address = NULL;
     char *acceptor_address = NULL;
     char *application_data = NULL;
-    int initiator_length = 0;
-    int acceptor_length = 0;
-    int application_length = 0;
+    Py_ssize_t initiator_length = 0;
+    Py_ssize_t acceptor_length = 0;
+    Py_ssize_t application_length = 0;
 
     PyObject *pychan_bindings = NULL;
     struct gss_channel_bindings_struct *input_chan_bindings;
