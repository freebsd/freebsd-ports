--- ./include/platform.h.orig	2014-01-01 00:45:23.000000000 +0100
+++ ./include/platform.h	2014-01-08 00:06:24.000000000 +0100
@@ -385,10 +385,6 @@
 # undef HAVE_STRVERSCMP
 #endif
 
-#if defined(__dietlibc__)
-# undef HAVE_STRCHRNUL
-#endif
-
 #if defined(__WATCOMC__)
 # undef HAVE_DPRINTF
 # undef HAVE_GETLINE
@@ -419,7 +415,7 @@
 /* These BSD-derived OSes share many similarities */
 #if (defined __digital__ && defined __unix__) \
  || defined __APPLE__ \
- || defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
+ || defined __OpenBSD__ || defined __NetBSD__
 # undef HAVE_CLEARENV
 # undef HAVE_FDATASYNC
 # undef HAVE_GETLINE
@@ -434,10 +430,26 @@
 # undef HAVE_UNLOCKED_LINE_OPS
 #endif
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__dietlibc__)
 # undef HAVE_STRCHRNUL
 #endif
 
+#if defined __FreeBSD__
+# undef HAVE_CLEARENV
+# undef HAVE_FDATASYNC
+# undef HAVE_MNTENT_H
+# undef HAVE_PTSNAME_R
+# undef HAVE_SYS_STATFS_H
+# undef HAVE_SIGHANDLER_T
+# undef HAVE_STRVERSCMP
+# undef HAVE_XTABS
+# undef HAVE_UNLOCKED_LINE_OPS
+# include <osreldate.h>
+# if __FreeBSD_version < 1000029
+#  undef HAVE_STRCHRNUL /* FreeBSD added strchrnul() between 1000028 and 1000029 */
+# endif
+#endif
+
 #if defined(__NetBSD__)
 # define HAVE_GETLINE 1  /* Recent NetBSD versions have getline() */
 #endif
