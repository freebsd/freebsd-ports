--- build/pkgs/giac/spkg-configure.m4.orig	2020-10-04 14:57:22 UTC
+++ build/pkgs/giac/spkg-configure.m4
@@ -2,7 +2,7 @@ SAGE_SPKG_CONFIGURE([giac], [
     SAGE_SPKG_DEPCHECK([pari], [
        dnl giac does not seem to reveal its patchlevel
        m4_pushdef([GIAC_MIN_VERSION], [1.5.0])
-       m4_pushdef([GIAC_MAX_VERSION], [1.5.999])
+       m4_pushdef([GIAC_MAX_VERSION], [1.6.1])
        AC_CACHE_CHECK([for giac >= ]GIAC_MIN_VERSION[, <= ]GIAC_MAX_VERSION, [ac_cv_path_GIAC], [
          AC_PATH_PROGS_FEATURE_CHECK([GIAC], [giac], [
             giac_version=$($ac_path_GIAC --version 2> /dev/null | tail -1)
