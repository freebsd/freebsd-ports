--- external/platform.m4.orig	2026-07-21 17:32:14 UTC
+++ external/platform.m4
@@ -36,13 +36,24 @@ AM_CONDITIONAL([HAVE_GENTOO], [test x"$osname" = xgent
 AM_CONDITIONAL([HAVE_DEBIAN], [test x"$osname" = xdebian])
 AM_CONDITIONAL([HAVE_GENTOO], [test x"$osname" = xgentoo])
 
-AC_CHECK_MEMBERS([struct ucred.pid, struct ucred.uid, struct ucred.gid], , ,
-                 [[#include <sys/socket.h>]])
+case "$host_os" in
+freebsd*)
+    AC_CHECK_MEMBERS([struct xucred.cr_pid, struct xucred.cr_uid,
+                      struct xucred.cr_gid], [],
+                     [AC_MSG_ERROR([struct xucred is not available])],
+                     [[#include <sys/types.h>
+#include <sys/ucred.h>]])
+    ;;
+*)
+    AC_CHECK_MEMBERS([struct ucred.pid, struct ucred.uid, struct ucred.gid], , ,
+                     [[#include <sys/socket.h>]])
 
-if test x"$ac_cv_member_struct_ucred_pid" = xyes -a \
-        x"$ac_cv_member_struct_ucred_uid" = xyes -a \
-        x"$ac_cv_member_struct_ucred_gid" = xyes ; then
-    AC_DEFINE([HAVE_UCRED], [1], [Define if struct ucred is available])
-else
-    AC_MSG_ERROR([struct ucred is not available])
-fi
+    if test x"$ac_cv_member_struct_ucred_pid" = xyes -a \
+            x"$ac_cv_member_struct_ucred_uid" = xyes -a \
+            x"$ac_cv_member_struct_ucred_gid" = xyes ; then
+        AC_DEFINE([HAVE_UCRED], [1], [Define if struct ucred is available])
+    else
+        AC_MSG_ERROR([struct ucred is not available])
+    fi
+    ;;
+esac
