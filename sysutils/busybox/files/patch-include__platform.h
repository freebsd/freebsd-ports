--- ./include/platform.h.orig	2011-08-28 12:59:56.000000000 +0200
+++ ./include/platform.h	2011-09-22 23:05:09.000000000 +0200
@@ -423,6 +423,15 @@
 
 #if defined(__FreeBSD__)
 # undef HAVE_STRCHRNUL
+
+# if __FreeBSD__ + 0 >= 2
+#  include <osreldate.h>
+#  if __FreeBSD_version >= 800067
+#   define HAVE_GETLINE 1 /* FreeBSD added getdelim(), getline(),
+			     stpncpy(), strnlen(), wcsnlen(),
+			     wcscasecmp(), and wcsncasecmp() in 800067 */
+#  endif
+# endif
 #endif
 
 #if defined(__NetBSD__)
