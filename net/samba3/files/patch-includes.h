--- include/includes.h.orig	Sat Mar 30 23:30:18 2002
+++ include/includes.h	Sat Mar 30 23:31:07 2002
@@ -1117,5 +1117,9 @@
 #define slprintf snprintf
 #define vslprintf vsnprintf
 
+#ifndef PAM_AUTHTOK_RECOVER_ERR
+#define PAM_AUTHTOK_RECOVER_ERR PAM_AUTHTOK_RECOVERY_ERR
+#endif
+
 #endif /* _INCLUDES_H */
 
