--- include/libbb.h.orig	2021-01-04 13:16:47 UTC
+++ include/libbb.h
@@ -106,7 +106,11 @@
 #  define updwtmpx updwtmp
 #  define _PATH_UTMPX _PATH_UTMP
 # else
+#ifndef __FreeBSD__
 #  include <utmp.h>
+#else
+#define  _PATH_UTMPX "/var/run/utx.active"
+#endif
 #  include <utmpx.h>
 #  if defined _PATH_UTMP && !defined _PATH_UTMPX
 #   define _PATH_UTMPX _PATH_UTMP
