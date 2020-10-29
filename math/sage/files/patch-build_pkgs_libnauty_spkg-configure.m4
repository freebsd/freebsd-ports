--- build/pkgs/libnauty/spkg-configure.m4.orig	2020-10-02 15:26:33 UTC
+++ build/pkgs/libnauty/spkg-configure.m4
@@ -2,6 +2,6 @@ SAGE_SPKG_CONFIGURE([libnauty], [
   SAGE_SPKG_DEPCHECK([nauty], [
     dnl The library is actually installed by the nauty spkg.
     AC_CHECK_HEADER([nauty/nauty.h], [], [sage_spkg_install_libnauty=yes])
-    AC_SEARCH_LIBS([nauty], [densenauty], [], [sage_spkg_install_libnauty=yes])
+    AC_SEARCH_LIBS([densenauty], [nauty], [], [sage_spkg_install_libnauty=yes])
   ])
 ])
