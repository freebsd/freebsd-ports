--- ./include/platform.h.orig	2013-06-29 17:00:01.000000000 +0200
+++ ./include/platform.h	2013-09-05 08:58:27.000000000 +0200
@@ -433,6 +433,18 @@
 
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
+#  if __FreeBSD_version >= 1000029
+#   define HAVE_STRCHRNUL 1 /* added short before 1000029 */
+#  endif
+# endif
 #endif
 
 #if defined(__NetBSD__)
