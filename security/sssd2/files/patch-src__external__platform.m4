--- src/external/platform.m4.orig	2023-05-05 08:11:07 UTC
+++ src/external/platform.m4
@@ -1,9 +1,10 @@ AC_ARG_WITH([os],
 AC_ARG_WITH([os],
-            [AC_HELP_STRING([--with-os=OS_TYPE], [Type of your operation system (fedora|redhat|suse|gentoo)])]
+            [AC_HELP_STRING([--with-os=OS_TYPE], [Type of your operation system (fedora|redhat|suse|gentoo|freebsd)])]
            )
 osname=""
 if test x"$with_os" != x ; then
     if test x"$with_os" = xfedora || \
+       test x"$with_os" = xfreebsd || \
        test x"$with_os" = xredhat || \
        test x"$with_os" = xsuse || \
        test x"$with_os" = xgentoo || \
@@ -25,6 +26,8 @@ if test x"$osname" = x ; then
         osname="debian"
     elif test -f /etc/gentoo-release ; then
         osname="gentoo"
+    elif test -f /etc/os-release ; then
+        osname="freebsd"
     fi
 
     AC_MSG_NOTICE([Detected operating system type: $osname])
@@ -35,6 +38,7 @@ AM_CONDITIONAL([HAVE_GENTOO], [test x"$osname" = xgent
 AM_CONDITIONAL([HAVE_SUSE], [test x"$osname" = xsuse])
 AM_CONDITIONAL([HAVE_DEBIAN], [test x"$osname" = xdebian])
 AM_CONDITIONAL([HAVE_GENTOO], [test x"$osname" = xgentoo])
+AM_CONDITIONAL([HAVE_FREEBSD], [test x"$osname" = xfreebsd])
 
 AS_CASE([$osname],
         [redhat], [AC_DEFINE_UNQUOTED([HAVE_REDHAT], 1, [Build with redhat config])],
@@ -42,10 +46,18 @@ AS_CASE([$osname],
         [suse], [AC_DEFINE_UNQUOTED([HAVE_SUSE], 1, [Build with suse config])],
         [gentoo], [AC_DEFINE_UNQUOTED([HAVE_GENTOO], 1, [Build with gentoo config])],
         [debian], [AC_DEFINE_UNQUOTED([HAVE_DEBIAN], 1, [Build with debian config])],
+        [freebsd], [AC_DEFINE_UNQUOTED([HAVE_FREEBSD], 1, [Build with freebsd config])],
         [AC_MSG_NOTICE([Build with $osname config])])
 
-AC_CHECK_MEMBERS([struct ucred.pid, struct ucred.uid, struct ucred.gid], , ,
+if test x"$osname" = x"freebsd"; then
+	AC_CHECK_MEMBERS([struct xucred.cr_pid, struct xucred.cr_uid, struct xucred.cr_gid], , , [[
+#include <sys/param.h>
+#include <sys/ucred.h>
+]])
+else
+	AC_CHECK_MEMBERS([struct ucred.pid, struct ucred.uid, struct ucred.gid], , ,
                  [[#include <sys/socket.h>]])
+fi
 
 if test x"$ac_cv_member_struct_ucred_pid" = xyes -a \
         x"$ac_cv_member_struct_ucred_uid" = xyes -a \
