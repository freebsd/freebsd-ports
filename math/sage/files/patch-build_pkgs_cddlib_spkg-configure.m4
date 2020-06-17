--- build/pkgs/cddlib/spkg-configure.m4.orig	2020-04-27 18:08:24 UTC
+++ build/pkgs/cddlib/spkg-configure.m4
@@ -24,13 +24,13 @@ SAGE_SPKG_CONFIGURE([cddlib], [
     dnl check, passing up a chance to detect cddlib on Fedora and Debian
     dnl for now. Once all of cddlib's consumers know about the new (or
     dnl both) locations, we can update this check to support them.
-    AC_CHECK_HEADER([cdd.h],[],[sage_spkg_install_cddlib=yes],[
-      #include <setoper.h>
-      #include <cddmp.h>
+    AC_CHECK_HEADER([cdd/cdd.h],[
+        dnl Both lattE and gfan try to link against libcddgmp (as
+        dnl opposed to libcdd).
+        AC_SEARCH_LIBS([dd_abs],[cddgmp],[],[sage_spkg_install_cddlib=yes])
+    ],[sage_spkg_install_cddlib=yes],[
+      #include <cdd/setoper.h>
+      #include <cdd/cddmp.h>
     ])
-
-    dnl Both lattE and gfan try to link against libcddgmp (as
-    dnl opposed to libcdd).
-    AC_SEARCH_LIBS([dd_abs],[cddgmp],[],[sage_spkg_install_cddlib=yes])
   ])
 ])
