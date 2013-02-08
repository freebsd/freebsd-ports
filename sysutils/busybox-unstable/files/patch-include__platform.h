--- ./include/platform.h.orig	2013-01-14 05:19:43.000000000 +0100
+++ ./include/platform.h	2013-01-21 21:26:34.000000000 +0100
@@ -433,6 +433,15 @@
 
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
