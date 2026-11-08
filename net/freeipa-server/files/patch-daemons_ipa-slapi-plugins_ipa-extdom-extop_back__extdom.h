--- daemons/ipa-slapi-plugins/ipa-extdom-extop/back_extdom.h.orig	2026-07-01 19:54:56 UTC
+++ daemons/ipa-slapi-plugins/ipa-extdom-extop/back_extdom.h
@@ -24,6 +24,13 @@
 #include <unistd.h>
 #include <pwd.h>
 #include <grp.h>
+#include <errno.h>
+
+#ifdef __FreeBSD__
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+#endif
 
 /* Possible results of lookup using a nss_* function.
  * Note: don't include nss.h as its path gets overriden by NSS library */
