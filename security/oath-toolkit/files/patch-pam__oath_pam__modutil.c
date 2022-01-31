--- pam_oath/pam_modutil.c.orig	2022-01-31 11:03:40 UTC
+++ pam_oath/pam_modutil.c
@@ -0,0 +1,82 @@
+#include <config.h>
+
+#ifndef HAVE_SECURITY_PAM_MODUTIL_H
+
+#include "pam_modutil.h"
+
+#ifdef HAVE_SECURITY_PAM_APPL_H
+#include <security/pam_appl.h>
+#endif
+#ifdef HAVE_SECURITY_PAM_MODULES_H
+#include <security/pam_modules.h>
+#endif
+
+#include <errno.h>
+#include <pwd.h>
+#include <stddef.h>
+#include <stdlib.h>
+#include <unistd.h>
+
+#define PWD_INITIAL_LENGTH      0x400
+#define PWD_ABSURD_PWD_LENGTH   0x4000
+
+void _pam_modutil_cleanup(pam_handle_t *pamh, void *data, int error_status) {
+    if (data) {
+        (void) free(data);
+    }
+}
+
+struct passwd *pam_modutil_getpwnam(pam_handle_t *pamh, const char *user) {
+    void *buffer = NULL;
+    size_t length = PWD_INITIAL_LENGTH;
+    long sc_init_length = sysconf(_SC_GETPW_R_SIZE_MAX);
+
+    if (sc_init_length != -1 && sc_init_length < PWD_ABSURD_PWD_LENGTH) {
+        length = (size_t) sc_init_length;
+    }
+
+    do {
+        int status;
+        void *new_buffer;
+        struct passwd *result = NULL;
+
+        new_buffer = realloc(buffer, sizeof(struct passwd) + length);
+        if (new_buffer == NULL) {
+            // out of memory
+            if (buffer) {
+                free(buffer);
+            }
+            return NULL;
+        }
+        buffer = new_buffer;
+
+        status = getpwnam_r(user, buffer,
+                            sizeof(struct passwd) + (char *) buffer,
+                            length, &result);
+        if (!status && result) {
+            status = pam_set_data(pamh, "_pammodutil_getpwnam", result,
+                                  _pam_modutil_cleanup);
+            if (status == PAM_SUCCESS) {
+                return result;
+            }
+            // unable to set data item
+            free(buffer);
+            return NULL;
+        }
+        if (status != ERANGE) {
+            // no matching record found (if status == 0)
+            // or getpwnam_r encountered an error
+            free(buffer);
+            return NULL;
+        }
+
+        length <<= 1;
+    } while (length < PWD_ABSURD_PWD_LENGTH);
+
+    // exceeded maximum buffer size
+    free(buffer);
+    return NULL;
+}
+#else
+typedef int make_iso_compilers_happy;
+#endif  /* HAVE_SECURITY_PAM_MODUTIL_H */
