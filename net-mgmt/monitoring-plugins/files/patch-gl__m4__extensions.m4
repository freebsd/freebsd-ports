--- gl/m4/extensions.m4.orig	2014-06-18 19:37:06 UTC
+++ gl/m4/extensions.m4
@@ -16,6 +16,7 @@
 #     warning: AC_COMPILE_IFELSE was called before AC_USE_SYSTEM_EXTENSIONS
 # or  warning: AC_RUN_IFELSE was called before AC_USE_SYSTEM_EXTENSIONS
 # the fix is
+m4_ifndef([AC_USE_SYSTEM_EXTENSIONS],[
 #   1) to ensure that AC_USE_SYSTEM_EXTENSIONS is never directly invoked
 #      but always AC_REQUIREd,
 #   2) to ensure that for each occurrence of
@@ -49,6 +50,7 @@
        except with this defined.])
     AC_DEFINE([_MINIX], [1],
       [Define to 1 if on MINIX.])
+])
     AC_DEFINE([_NETBSD_SOURCE], [1],
       [Define to 1 to make NetBSD features available.  MINIX 3 needs this.])
   fi
