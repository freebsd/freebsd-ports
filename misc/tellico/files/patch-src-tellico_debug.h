--- src/tellico_debug.h.orig	2008-04-07 19:19:21.000000000 +0200
+++ src/tellico_debug.h	2008-04-07 19:48:56.000000000 +0200
@@ -22,6 +22,10 @@
 // std::clock_t
 #include <ctime>
 
+# if defined(__GNUC_PREREQ__) && !defined(__GNUC_PREREQ)
+#   define __GNUC_PREREQ __GNUC_PREREQ__
+# endif
+
 # if defined __cplusplus ? __GNUC_PREREQ (2, 6) : __GNUC_PREREQ (2, 4)
 #   define MY_FUNCTION  __PRETTY_FUNCTION__
 # else
