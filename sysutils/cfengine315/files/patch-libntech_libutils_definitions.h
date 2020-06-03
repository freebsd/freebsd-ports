--- libntech/libutils/definitions.h.orig	2020-05-19 08:05:50.000000000 -0700
+++ libntech/libutils/definitions.h	2020-05-20 19:48:00.299686000 -0700
@@ -58,7 +58,7 @@
  *****************************************************************************/
 #ifdef __FreeBSD__
 #  define CF_SYSTEM_GROUP "wheel"
-#elseif __Solaris__
+#elif __Solaris__
 #  define CF_SYSTEM_GROUP "sys"
 #else
 #  define CF_SYSTEM_GROUP "root"
