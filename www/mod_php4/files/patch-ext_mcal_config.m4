--- ext/mcal/config.m4.orig	Wed Mar 27 11:26:16 2002
+++ ext/mcal/config.m4	Fri Jan  3 19:38:46 2003
@@ -41,5 +41,14 @@
   PHP_SUBST(MCAL_SHARED_LIBADD)
   AC_DEFINE(HAVE_MCAL,1,[ ])
   PHP_NEW_EXTENSION(mcal, php_mcal.c, $ext_shared)
+  cat >> confdefs.h <<\EOF
+/* Interfaces to callbacks in libmcal */
+#include <mcal/mcal.h>
+void cc_searched (unsigned long cal_uid) {}
+void cc_fetched(const CALEVENT *event) {}
+void cc_login(const char **user, const char **pwd) {}
+void cc_vlog(const char *fmt,va_list ap) {}
+void cc_vdlog(const char *fmt,va_list ap) {}
+EOF
 fi
 
