--- include/includes.h.orig	Tue Apr  2 17:23:04 2002
+++ include/includes.h	Tue Apr  2 17:23:08 2002
@@ -27,6 +27,11 @@
 
 #include "local.h"
 
+#ifdef __FreeBSD__
+#define DEFAULT_PRINTING PRINT_BSD
+#define PRINTCAP_NAME "/etc/printcap"
+#endif /* __FreeBSD__ */
+
 #ifdef AIX
 #define DEFAULT_PRINTING PRINT_AIX
 #define PRINTCAP_NAME "/etc/qconfig"
@@ -1119,6 +1124,10 @@
    for snprintf and vsnprintf */
 #define slprintf snprintf
 #define vslprintf vsnprintf
+
+#ifndef PAM_AUTHTOK_RECOVER_ERR
+#define PAM_AUTHTOK_RECOVER_ERR PAM_AUTHTOK_RECOVERY_ERR
+#endif
 
 #endif /* _INCLUDES_H */
 
