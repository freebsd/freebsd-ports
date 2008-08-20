--- gl/m4/extensions.m4.orig	2007-01-24 22:47:25.000000000 +0000
+++ gl/m4/extensions.m4	2008-07-14 15:04:08.000000000 +0000
@@ -18,2 +18,3 @@
 # typically due to standards-conformance issues.
+m4_ifndef([AC_USE_SYSTEM_EXTENSIONS],[
 AC_DEFUN([AC_USE_SYSTEM_EXTENSIONS],
@@ -51,2 +52,3 @@
 ])
+])
 
