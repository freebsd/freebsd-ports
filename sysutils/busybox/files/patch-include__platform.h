--- ./include/platform.h.orig	2012-07-02 14:08:25.000000000 +0000
+++ ./include/platform.h	2012-07-17 02:08:37.000000000 +0000
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
