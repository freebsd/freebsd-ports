--- aclocal.m4.dist	Thu Oct 10 11:39:35 2002
+++ aclocal.m4	Mon Oct 21 09:34:35 2002
@@ -11,7 +11,7 @@
 # even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 # PARTICULAR PURPOSE.
 
-# gettext.m4 serial 13 (gettext-0.11.1)
+# gettext.m4 serial 17 (gettext-0.11.5)
 dnl Copyright (C) 1995-2002 Free Software Foundation, Inc.
 dnl This file is free software, distributed under the terms of the GNU
 dnl General Public License.  As a special exception to the GNU General
@@ -46,7 +46,9 @@
 dnl    $(top_builddir)/intl/libintl.a will be created.
 dnl If NEEDSYMBOL is specified and is 'need-ngettext', then GNU gettext
 dnl    implementations (in libc or libintl) without the ngettext() function
-dnl    will be ignored.
+dnl    will be ignored.  If NEEDSYMBOL is specified and is
+dnl    'need-formatstring-macros', then GNU gettext implementations that don't
+dnl    support the ISO C 99 <inttypes.h> formatstring macros will be ignored.
 dnl INTLDIR is used to find the intl libraries.  If empty,
 dnl    the value `$(top_builddir)/intl/' is used.
 dnl
@@ -73,9 +75,9 @@
   ifelse([$1], [], , [ifelse([$1], [external], , [ifelse([$1], [no-libtool], , [ifelse([$1], [use-libtool], ,
     [errprint([ERROR: invalid first argument to AM_GNU_GETTEXT
 ])])])])])
-  ifelse([$2], [], , [ifelse([$2], [need-ngettext], ,
+  ifelse([$2], [], , [ifelse([$2], [need-ngettext], , [ifelse([$2], [need-formatstring-macros], ,
     [errprint([ERROR: invalid second argument to AM_GNU_GETTEXT
-])])])
+])])])])
   define(gt_included_intl, ifelse([$1], [external], [no], [yes]))
   define(gt_libtool_suffix_prefix, ifelse([$1], [use-libtool], [l], []))
 
@@ -88,6 +90,21 @@
   AC_REQUIRE([AC_LIB_PREPARE_PREFIX])
   AC_REQUIRE([AC_LIB_RPATH])
 
+  dnl Sometimes libintl requires libiconv, so first search for libiconv.
+  dnl Ideally we would do this search only after the
+  dnl      if test "$USE_NLS" = "yes"; then
+  dnl        if test "$gt_cv_func_gnugettext_libc" != "yes"; then
+  dnl tests. But if configure.in invokes AM_ICONV after AM_GNU_GETTEXT
+  dnl the configure script would need to contain the same shell code
+  dnl again, outside any 'if'. There are two solutions:
+  dnl - Invoke AM_ICONV_LINKFLAGS_BODY here, outside any 'if'.
+  dnl - Control the expansions in more detail using AC_PROVIDE_IFELSE.
+  dnl Since AC_PROVIDE_IFELSE is only in autoconf >= 2.52 and not
+  dnl documented, we avoid it.
+  ifelse(gt_included_intl, yes, , [
+    AC_REQUIRE([AM_ICONV_LINKFLAGS_BODY])
+  ])
+
   AC_MSG_CHECKING([whether NLS is requested])
   dnl Default is enabled NLS
   AC_ARG_ENABLE(nls,
@@ -123,13 +140,20 @@
         dnl to fall back to GNU NLS library.
 
         dnl Add a version number to the cache macros.
-        define([gt_api_version], ifelse([$2], [need-ngettext], 2, 1))
+        define([gt_api_version], ifelse([$2], [need-formatstring-macros], 3, ifelse([$2], [need-ngettext], 2, 1)))
         define([gt_cv_func_gnugettext_libc], [gt_cv_func_gnugettext]gt_api_version[_libc])
         define([gt_cv_func_gnugettext_libintl], [gt_cv_func_gnugettext]gt_api_version[_libintl])
 
         AC_CACHE_CHECK([for GNU gettext in libc], gt_cv_func_gnugettext_libc,
          [AC_TRY_LINK([#include <libintl.h>
-extern int _nl_msg_cat_cntr;
+]ifelse([$2], [need-formatstring-macros],
+[#ifndef __GNU_GETTEXT_SUPPORTED_REVISION
+#define __GNU_GETTEXT_SUPPORTED_REVISION(major) ((major) == 0 ? 0 : -1)
+#endif
+changequote(,)dnl
+typedef int array [2 * (__GNU_GETTEXT_SUPPORTED_REVISION(0) >= 1) - 1];
+changequote([,])dnl
+], [])[extern int _nl_msg_cat_cntr;
 extern int *_nl_domain_bindings;],
             [bindtextdomain ("", "");
 return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_domain_bindings],
@@ -154,30 +178,42 @@
             LIBS="$LIBS $LIBINTL"
             dnl Now see whether libintl exists and does not depend on libiconv.
             AC_TRY_LINK([#include <libintl.h>
-extern int _nl_msg_cat_cntr;
-extern int *_nl_domain_bindings;
+]ifelse([$2], [need-formatstring-macros],
+[#ifndef __GNU_GETTEXT_SUPPORTED_REVISION
+#define __GNU_GETTEXT_SUPPORTED_REVISION(major) ((major) == 0 ? 0 : -1)
+#endif
+changequote(,)dnl
+typedef int array [2 * (__GNU_GETTEXT_SUPPORTED_REVISION(0) >= 1) - 1];
+changequote([,])dnl
+], [])[extern int _nl_msg_cat_cntr;
 extern
 #ifdef __cplusplus
 "C"
 #endif
 const char *_nl_expand_alias ();],
               [bindtextdomain ("", "");
-return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_domain_bindings + *_nl_expand_alias (0)],
+return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_expand_alias (0)],
               gt_cv_func_gnugettext_libintl=yes,
               gt_cv_func_gnugettext_libintl=no)
             dnl Now see whether libintl exists and depends on libiconv.
             if test "$gt_cv_func_gnugettext_libintl" != yes && test -n "$LIBICONV"; then
               LIBS="$LIBS $LIBICONV"
               AC_TRY_LINK([#include <libintl.h>
-extern int _nl_msg_cat_cntr;
-extern int *_nl_domain_bindings;
+]ifelse([$2], [need-formatstring-macros],
+[#ifndef __GNU_GETTEXT_SUPPORTED_REVISION
+#define __GNU_GETTEXT_SUPPORTED_REVISION(major) ((major) == 0 ? 0 : -1)
+#endif
+changequote(,)dnl
+typedef int array [2 * (__GNU_GETTEXT_SUPPORTED_REVISION(0) >= 1) - 1];
+changequote([,])dnl
+], [])[extern int _nl_msg_cat_cntr;
 extern
 #ifdef __cplusplus
 "C"
 #endif
 const char *_nl_expand_alias ();],
                 [bindtextdomain ("", "");
-return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_domain_bindings + *_nl_expand_alias (0)],
+return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_expand_alias (0)],
                [LIBINTL="$LIBINTL $LIBICONV"
                 LTLIBINTL="$LTLIBINTL $LTLIBICONV"
                 gt_cv_func_gnugettext_libintl=yes
@@ -465,7 +501,7 @@
         ;;
       esac
     done],
-   [# Capture the value of obsolete $ALL_LINGUAS because we need it to compute
+   [# Capture the value of obsolete ALL_LINGUAS because we need it to compute
     # POFILES, GMOFILES, UPDATEPOFILES, DUMMYPOFILES, CATALOGS. But hide it
     # from automake.
     eval 'ALL_LINGUAS''="$ALL_LINGUAS"'
@@ -494,6 +530,10 @@
   AC_REQUIRE([AC_FUNC_ALLOCA])dnl
   AC_REQUIRE([AC_FUNC_MMAP])dnl
   AC_REQUIRE([jm_GLIBC21])dnl
+  AC_REQUIRE([gt_INTDIV0])dnl
+  AC_REQUIRE([jm_AC_TYPE_UINTMAX_T])dnl
+  AC_REQUIRE([gt_HEADER_INTTYPES_H])dnl
+  AC_REQUIRE([gt_INTTYPES_PRI])dnl
 
   AC_CHECK_HEADERS([argz.h limits.h locale.h nl_types.h malloc.h stddef.h \
 stdlib.h string.h unistd.h sys/param.h])
@@ -503,7 +543,9 @@
 
   AM_ICONV
   AM_LANGINFO_CODESET
-  AM_LC_MESSAGES
+  if test $ac_cv_header_locale_h = yes; then
+    AM_LC_MESSAGES
+  fi
 
   dnl intl/plural.c is generated from intl/plural.y. It requires bison,
   dnl because plural.y uses bison specific features. It requires at least
@@ -1322,7 +1364,7 @@
 AC_LIB_PROG_LD_GNU
 ])
 
-# iconv.m4 serial AM3 (gettext-0.11)
+# iconv.m4 serial AM4 (gettext-0.11.3)
 dnl Copyright (C) 2000-2002 Free Software Foundation, Inc.
 dnl This file is free software, distributed under the terms of the GNU
 dnl General Public License.  As a special exception to the GNU General
@@ -1332,11 +1374,8 @@
 
 dnl From Bruno Haible.
 
-AC_DEFUN([AM_ICONV_LINK],
+AC_DEFUN([AM_ICONV_LINKFLAGS_BODY],
 [
-  dnl Some systems have iconv in libc, some have it in libiconv (OSF/1 and
-  dnl those with the standalone portable GNU libiconv installed).
-
   dnl Prerequisites of AC_LIB_LINKFLAGS_BODY.
   AC_REQUIRE([AC_LIB_PREPARE_PREFIX])
   AC_REQUIRE([AC_LIB_RPATH])
@@ -1344,6 +1383,16 @@
   dnl Search for libiconv and define LIBICONV, LTLIBICONV and INCICONV
   dnl accordingly.
   AC_LIB_LINKFLAGS_BODY([iconv])
+])
+
+AC_DEFUN([AM_ICONV_LINK],
+[
+  dnl Some systems have iconv in libc, some have it in libiconv (OSF/1 and
+  dnl those with the standalone portable GNU libiconv installed).
+
+  dnl Search for libiconv and define LIBICONV, LTLIBICONV and INCICONV
+  dnl accordingly.
+  AC_REQUIRE([AM_ICONV_LINKFLAGS_BODY])
 
   dnl Add $INCICONV to CPPFLAGS before performing the following checks,
   dnl because if the user has installed libiconv and not disabled its use
@@ -1393,7 +1442,7 @@
 
 AC_DEFUN([AM_ICONV],
 [
-  AC_REQUIRE([AM_ICONV_LINK])
+  AM_ICONV_LINK
   if test "$am_cv_func_iconv" = yes; then
     AC_MSG_CHECKING([for iconv declaration])
     AC_CACHE_VAL(am_cv_proto_iconv, [
