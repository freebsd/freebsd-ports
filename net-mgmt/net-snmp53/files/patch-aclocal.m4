--- aclocal.m4.orig	Tue Sep 18 17:08:01 2001
+++ aclocal.m4	Mon Jan 21 10:38:40 2002
@@ -196,8 +196,23 @@
 AC_DEFUN([AC_PROG_LIBTOOL],
 [AC_REQUIRE([AC_LIBTOOL_SETUP])dnl
 
+# Save cache, so that ltconfig can load it
+AC_CACHE_SAVE
+
+# Actually configure libtool.  ac_aux_dir is where install-sh is found.
+CC="$CC" CFLAGS="$CFLAGS" CPPFLAGS="$CPPFLAGS" \
+LD="$LD" LDFLAGS="$LDFLAGS" LIBS="$LIBS" \
+LN_S="$LN_S" NM="$NM" RANLIB="$RANLIB" \
+DLLTOOL="$DLLTOOL" AS="$AS" OBJDUMP="$OBJDUMP" \
+${CONFIG_SHELL-/bin/sh} %%LTCONFIG%% --no-reexec \
+$libtool_flags --no-verify --disable-ltlibs --release-ignore %%LTMAIN%% $lt_target \
+|| AC_MSG_ERROR([libtool configure failed])
+
+# Reload cache, that may have been modified by ltconfig
+AC_CACHE_LOAD
+
 # This can be used to rebuild libtool when needed
-LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
+LIBTOOL_DEPS="--disable-ltlibs --release-ignore %%LTMAIN%%"
 
 # Always use our own libtool.
 LIBTOOL='$(SHELL) $(top_builddir)/libtool'
@@ -224,6 +239,11 @@
 AC_REQUIRE([AC_EXEEXT])dnl
 dnl
 
+case "$target" in
+NONE) lt_target="$host" ;;
+*) lt_target="$target" ;;
+esac
+
 _LT_AC_PROG_ECHO_BACKSLASH
 # Only perform the check for file, if the check method requires it
 case $deplibs_check_method in
@@ -875,7 +895,7 @@
 # All known linkers require a `.a' archive for static linking (except M$VC,
 # which needs '.lib').
 libext=a
-ltmain="$ac_aux_dir/ltmain.sh"
+ltmain="--disable-ltlibs --release-ignore %%LTMAIN%%"
 ofile="$default_ofile"
 with_gnu_ld="$lt_cv_prog_gnu_ld"
 need_locks="$enable_libtool_lock"
