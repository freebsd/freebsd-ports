--- configure.sh.orig	Thu Apr 27 10:32:23 2006
+++ configure.sh	Thu Apr 27 10:33:46 2006
@@ -1061,6 +1061,7 @@
 	AC_LIBS="$AC_LIBS -lz"
 	unset BUILD_MAGIC
     fi
+    unset BUILD_MAGIC
 
     if [ "$BUILD_MAGIC" ]; then
 	case $ac_os in
@@ -1106,8 +1107,8 @@
     AC_SUB CFMAGIC	"cfmagic"
 else
     AC_SUB LIBMAGIC ""
-    AC_SUB MAGIC_HEADER ""
-    AC_SUB MAGIC_LIB ""
+    AC_SUB MAGIC_HEADER "-I${LOCALBASE}/include"
+    AC_SUB MAGIC_LIB "-L${LOCALBASE}/lib"
     AC_SUB MAKE_MAGIC ":"
     AC_SUB CFMAGIC	""
 fi
