--- aclocal.m4.orig	Tue Jan 22 12:34:25 2002
+++ aclocal.m4	Tue Jan 22 12:34:51 2002
@@ -135,7 +135,7 @@
 LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
 
 # Always use our own libtool.
-LIBTOOL='$(SHELL) $(top_builddir)/libtool'
+LIBTOOL="${LIBTOOL}"
 AC_SUBST(LIBTOOL)dnl
 
 # Prevent multiple expansion
