--- net/http/http_auth_gssapi_posix.h.orig	2022-02-07 13:39:41 UTC
+++ net/http/http_auth_gssapi_posix.h
@@ -20,6 +20,9 @@
 #if defined(OS_APPLE)
 #include <GSS/gssapi.h>
 #elif defined(OS_FREEBSD)
+#ifndef GSS_C_DELEG_POLICY_FLAG
+#define GSS_C_DELEG_POLICY_FLAG 32768
+#endif
 #include <gssapi/gssapi.h>
 #else
 #include <gssapi.h>
