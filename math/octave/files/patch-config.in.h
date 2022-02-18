--- config.in.h.orig	2021-10-30 14:20:24 UTC
+++ config.in.h
@@ -1153,11 +1153,11 @@
 /* Define to 1 if you have the `m' library (-lm). */
 #undef HAVE_LIBM
 
-/* Define to 1 if you have the <libqhull.h> header file. */
-#undef HAVE_LIBQHULL_H
+/* Define to 1 if you have the <libqhull_r.h> header file. */
+#undef HAVE_LIBQHULL_R_H
 
-/* Define to 1 if you have the <libqhull/libqhull.h> header file. */
-#undef HAVE_LIBQHULL_LIBQHULL_H
+/* Define to 1 if you have the <libqhull_r/libqhull_r.h> header file. */
+#undef HAVE_LIBQHULL_R_LIBQHULL_R_H
 
 /* Define to 1 if you have the `sun' library (-lsun). */
 #undef HAVE_LIBSUN
@@ -1493,15 +1493,6 @@
 /* Define to 1 if Qhull is available. */
 #undef HAVE_QHULL
 
-/* Define to 1 if you have the <qhull.h> header file. */
-#undef HAVE_QHULL_H
-
-/* Define to 1 if you have the <qhull/libqhull.h> header file. */
-#undef HAVE_QHULL_LIBQHULL_H
-
-/* Define to 1 if you have the <qhull/qhull.h> header file. */
-#undef HAVE_QHULL_QHULL_H
-
 /* Define to 1 if you have the `qInstallMessageHandler' function. */
 #undef HAVE_QINSTALLMESSAGEHANDLER
 
@@ -2252,7 +2243,7 @@
 #undef NEED_MKTIME_WORKING
 
 /* Define to 1 if the Qhull library needs a qh_version variable defined. */
-#undef NEED_QHULL_VERSION
+#undef NEED_QHULL_R_VERSION
 
 /* Define to 1 to enable general improvements of setlocale. */
 #undef NEED_SETLOCALE_IMPROVED
