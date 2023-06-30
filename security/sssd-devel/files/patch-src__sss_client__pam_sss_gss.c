--- src/sss_client/pam_sss_gss.c.orig	2023-05-05 08:11:07 UTC
+++ src/sss_client/pam_sss_gss.c
@@ -22,7 +22,7 @@
 #include <stddef.h>
 #include <stdbool.h>
 #include <security/pam_modules.h>
-#include <security/pam_ext.h>
+#include <security/pam_appl.h>
 #include <gssapi.h>
 #include <gssapi/gssapi_ext.h>
 #include <gssapi/gssapi_generic.h>
@@ -46,7 +46,6 @@ bool debug_enabled;
 #define ERROR(pamh, fmt, ...) do { \
     if (debug_enabled) { \
         pam_error(pamh, "pam_sss_gss: " fmt, ## __VA_ARGS__); \
-        pam_syslog(pamh, LOG_ERR, fmt, ## __VA_ARGS__); \
     } \
 } while (0)
 
