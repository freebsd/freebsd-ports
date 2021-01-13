--- m4/libxc.m4.orig	2020-07-07 14:26:13 UTC
+++ m4/libxc.m4
@@ -57,17 +57,13 @@ AC_DEFUN([AC_CHECK_LIBXC],
 
   LIBS="$LIBS -lxc"
    AC_MSG_CHECKING([for LIBXC library])
-   AC_LINK_IFELSE([[
-program main
-
-  call xc_f90_family_from_id()
-end]], ac_libxc_ok=yes, ac_libxc_ok=no)
+   ac_libxc_ok=yes
    AC_MSG_RESULT([$ac_libxc_ok])
    LIBS="$LIBS_SVG"
    LDFLAGS="$LDFLAGS_SVG"
    FCFLAGS="$FCFLAGS_SVG"
    if test "$ac_libxc_ok" = "yes"; then
-      LIBXC_LIBS="-lxc"
+      LIBXC_LIBS="-lxc -lxcf90"
       AS_IF([test -n "$LIBXC_PATH_LIBDIR"], [LIBXC_LIBS="-L$LIBXC_PATH_LIBDIR $LIBXC_LIBS"])
       AC_SUBST([LIBXC_LIBS])
    fi
