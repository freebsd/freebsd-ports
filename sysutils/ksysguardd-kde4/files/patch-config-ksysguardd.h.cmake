--- ./config-ksysguardd.h.cmake.orig	2011-02-25 22:54:48.000000000 +0100
+++ ./config-ksysguardd.h.cmake	2011-03-05 16:30:54.367061295 +0100
@@ -1,3 +1,4 @@
 #cmakedefine HAVE_LMSENSORS 1
 #cmakedefine HAVE_XRES 1
 #cmakedefine HAVE_SYS_INOTIFY_H 1
+#define kde_socklen_t socklen_t
