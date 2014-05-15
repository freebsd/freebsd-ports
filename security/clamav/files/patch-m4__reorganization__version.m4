--- m4/reorganization/version.m4.orig	2014-05-15 13:29:00.000000000 -0300
+++ m4/reorganization/version.m4	2014-05-15 13:29:27.000000000 -0300
@@ -8,6 +8,8 @@
 LIBCLAMAV_VERSION="$LC_CURRENT":"$LC_REVISION":"$LC_AGE"
 AC_SUBST([LIBCLAMAV_VERSION])
 
+major=`expr $LC_CURRENT - $LC_AGE`
+
 AC_DEFINE_UNQUOTED([LIBCLAMAV_FULLVER], "$major.$LC_AGE.$LC_REVISION",
         ["Full library version number"])
 
