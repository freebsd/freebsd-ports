--- ./srclib/apr/build/apr_hints.m4.orig	2009-11-17 09:28:12.000000000 -0500
+++ ./srclib/apr/build/apr_hints.m4	2010-05-06 19:37:54.280731298 -0400
@@ -159,11 +159,7 @@
 	;;
     *-freebsd*)
         APR_SETIFNULL(apr_lock_method, [USE_FLOCK_SERIALIZE])
-        if test -x /sbin/sysctl; then
-            os_version=`/sbin/sysctl -n kern.osreldate`
-        else
-            os_version=000000
-        fi
+        os_version="900010"
         # 502102 is when libc_r switched to libpthread (aka libkse).
         if test $os_version -ge "502102"; then
           apr_cv_pthreads_cflags="none"
