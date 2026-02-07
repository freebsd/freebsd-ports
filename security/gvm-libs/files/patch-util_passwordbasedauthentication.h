--- util/passwordbasedauthentication.h	2021-09-04 20:50:39.448395000 -0500
+++ util/passwordbasedauthentication.h	2021-09-04 20:50:57.245603000 -0500
@@ -18,6 +18,12 @@
 #ifndef _GVM_PASSWORDBASEDAUTHENTICATION_H
 #define _GVM_PASSWORDBASEDAUTHENTICATION_H
 
+#if defined(__FreeBSD__) && __FreeBSD__ < 12
+#define HAS_CRYPT_R 0
+#else
+#define HAS_CRYPT_R 1
+#endif
+
 /* max amount of applied pepper */
 #define MAX_PEPPER_SIZE 4
 /* is used when count is 0 on init*/
