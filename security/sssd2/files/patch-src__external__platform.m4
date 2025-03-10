--- src/external/platform.m4.orig	2024-12-07 08:35:28.095610000 -0800
+++ src/external/platform.m4	2024-12-07 08:39:28.615868000 -0800
@@ -1,9 +1,10 @@
 AC_ARG_WITH([os],
-            [AC_HELP_STRING([--with-os=OS_TYPE], [Type of your operation system (fedora|redhat|suse|gentoo)])]
+            [AC_HELP_STRING([--with-os=OS_TYPE], [Type of your operation system (fedora|freebsd|redhat|suse|gentoo)])]
            )
 osname=""
 if test x"$with_os" != x ; then
     if test x"$with_os" = xfedora || \
+       test x"$with_os" = xfreebsd || \
        test x"$with_os" = xredhat || \
        test x"$with_os" = xsuse || \
        test x"$with_os" = xgentoo || \
@@ -29,6 +30,8 @@
         . /etc/os-release
         if ([[ "${ID}" = "suse" ]]) || ([[ "${ID_LIKE#*suse*}" != "${ID_LIKE}" ]]); then
             osname="suse"
+        elif ([[ "${ID}" = "freebsd" ]]) || ([[ "${ID_LIKE#*freebsd*}" != "${ID_LIKE}" ]]); then
+            osname="freebsd"
         fi
     fi
 
@@ -36,6 +39,7 @@
 fi
 
 AM_CONDITIONAL([HAVE_FEDORA], [test x"$osname" = xfedora])
+AM_CONDITIONAL([HAVE_FREEBSD], [test x"$osname" = xfreebsd])
 AM_CONDITIONAL([HAVE_REDHAT], [test x"$osname" = xredhat])
 AM_CONDITIONAL([HAVE_SUSE], [test x"$osname" = xsuse])
 AM_CONDITIONAL([HAVE_DEBIAN], [test x"$osname" = xdebian])
@@ -44,14 +48,23 @@
 AS_CASE([$osname],
         [redhat], [AC_DEFINE_UNQUOTED([HAVE_REDHAT], 1, [Build with redhat config])],
         [fedora], [AC_DEFINE_UNQUOTED([HAVE_FEDORA], 1, [Build with fedora config])],
+        [freebsd], [AC_DEFINE_UNQUOTED([HAVE_FREEBSD], 1, [Build with freebsd config])],
         [suse], [AC_DEFINE_UNQUOTED([HAVE_SUSE], 1, [Build with suse config])],
         [gentoo], [AC_DEFINE_UNQUOTED([HAVE_GENTOO], 1, [Build with gentoo config])],
         [debian], [AC_DEFINE_UNQUOTED([HAVE_DEBIAN], 1, [Build with debian config])],
         [AC_MSG_NOTICE([Build with $osname config])])
 
-AC_CHECK_MEMBERS([struct ucred.pid, struct ucred.uid, struct ucred.gid], , ,
-                 [[#include <sys/socket.h>]])
+if test x"$osname" = x"freebsd"; then
+       AC_CHECK_MEMBERS([struct xucred.cr_pid, struct xucred.cr_uid, struct xucred.cr_gid], , , [[
+#include <sys/param.h>
+#include <sys/ucred.h>
+]])
+else
+       AC_CHECK_MEMBERS([struct ucred.pid, struct ucred.uid, struct ucred.gid], , ,
+                  [[#include <sys/socket.h>]])
+fi
 
+
 if test x"$ac_cv_member_struct_ucred_pid" = xyes -a \
         x"$ac_cv_member_struct_ucred_uid" = xyes -a \
         x"$ac_cv_member_struct_ucred_gid" = xyes ; then
