--- ext/mcal/config.m4.orig	Tue Mar 27 22:34:31 2001
+++ ext/mcal/config.m4	Fri Nov 30 09:26:56 2001
@@ -44,5 +44,14 @@
   PHP_SUBST(MCAL_SHARED_LIBADD)
   AC_DEFINE(HAVE_MCAL,1,[ ])
   PHP_EXTENSION(mcal,$ext_shared)
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
 
