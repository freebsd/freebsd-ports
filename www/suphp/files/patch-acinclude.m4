--- acinclude.m4.orig	2006-10-18 13:42:07.000000000 -0700
+++ acinclude.m4	2007-11-11 02:15:56.000000000 -0800
@@ -40,7 +40,7 @@
 dnl value of apr_config to fetch any necessary build/link information.
 dnl
 
-AC_DEFUN(APR_FIND_APR, [
+AC_DEFUN([APR_FIND_APR], [
   apr_found="no"
 
   if test "$ac_cv_emxos2" = "yes"; then
