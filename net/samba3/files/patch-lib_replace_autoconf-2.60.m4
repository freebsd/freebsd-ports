--- lib/replace/autoconf-2.60.m4.orig	2007-11-15 03:15:03.000000000 +0000
+++ lib/replace/autoconf-2.60.m4	2008-06-12 17:56:42.000000000 +0000
@@ -179,6 +179,7 @@
 # ------------------------
 # Enable extensions on systems that normally disable them,
 # typically due to standards-conformance issues.
+m4_ifndef([AC_USE_SYSTEM_EXTENSIONS],[
 AC_DEFUN([AC_USE_SYSTEM_EXTENSIONS],
 [
   AC_BEFORE([$0], [AC_COMPILE_IFELSE])
@@ -208,3 +209,4 @@
     AC_DEFINE([__EXTENSIONS__])
   AC_DEFINE([_POSIX_PTHREAD_SEMANTICS])
 ])
+])
