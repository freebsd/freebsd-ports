--- aclocal.m4.orig	Wed Jul 17 17:13:45 2002
+++ aclocal.m4	Wed Jul 17 17:14:40 2002
@@ -589,7 +589,7 @@
 LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
 
 # Always use our own libtool.
-LIBTOOL='$(SHELL) $(top_builddir)/libtool'
+LIBTOOL='$(SHELL) ${LOCALBASE}/bin/libtool'
 AC_SUBST(LIBTOOL)dnl
 
 # Prevent multiple expansion
