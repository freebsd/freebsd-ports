--- aclocal.m4.orig	Tue Jan 29 21:32:47 2002
+++ aclocal.m4	Sun Jul  7 18:21:47 2002
@@ -39,7 +39,7 @@
 AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
 AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
 AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
-AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
+AM_MISSING_PROG(AUTOHEADER, autoheader213, $missing_dir)
 AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
 AC_REQUIRE([AC_PROG_MAKE_SET])])
 
