--- aclocal.m4.orig	Fri Sep 20 13:11:18 2002
+++ aclocal.m4	Thu Oct 10 16:57:09 2002
@@ -1701,9 +1701,10 @@
 
 # This can be used to rebuild libtool when needed
 LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
+$ac_aux_dir/ltconfig $LIBTOOL_DEPS
 
 # Always use our own libtool.
-LIBTOOL='$(SHELL) $(top_builddir)/libtool'
+LIBTOOL='$(SHELL) ${LOCALBASE}/bin/libtool'
 AC_SUBST(LIBTOOL)dnl
 
 # Prevent multiple expansion
