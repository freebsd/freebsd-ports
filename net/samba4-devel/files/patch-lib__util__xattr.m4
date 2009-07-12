--- ./lib/util/xattr.m4.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./lib/util/xattr.m4	2009-07-12 02:39:36.000000000 +0000
@@ -1,14 +1,30 @@
 dnl ############################################
 dnl use flistxattr as the key function for having 
 dnl sufficient xattr support for posix xattr backend
-AC_CHECK_HEADERS(sys/attributes.h attr/xattr.h sys/xattr.h)
+AC_CHECK_HEADERS([		\
+	sys/attributes.h	\
+	attr/xattr.h		\
+	sys/xattr.h		\
+	sys/extattr.h		\
+	sys/uio.h		\
+])
 AC_SEARCH_LIBS_EXT(flistxattr, [attr], XATTR_LIBS)
 AC_CHECK_FUNC_EXT(flistxattr, $XATTR_LIBS)
+# Check if we have extattr API
+case "$host_os" in
+        *freebsd4* | *dragonfly* )
+		AC_DEFINE(BROKEN_EXTATTR,1,[Have broken extattr API])
+		;;
+	*)
+		AC_CHECK_FUNC_EXT(extattr_list_file, $XATTR_LIBS)
+		;;
+esac
+
 SMB_EXT_LIB(XATTR,[${XATTR_LIBS}],[${XATTR_CFLAGS}],[${XATTR_CPPFLAGS}],[${XATTR_LDFLAGS}])
 if test x"$ac_cv_func_ext_flistxattr" = x"yes"; then
 	AC_CACHE_CHECK([whether xattr interface takes additional options], smb_attr_cv_xattr_add_opt,
 	[old_LIBS=$LIBS
-	 LIBS="$LIBS $XATTRLIBS"
+	 LIBS="$LIBS $XATTR_LIBS"
 	 AC_TRY_COMPILE([
 	 	#include <sys/types.h>
 		#if HAVE_ATTR_XATTR_H
@@ -28,5 +44,7 @@
 	fi
 	AC_DEFINE(HAVE_XATTR_SUPPORT,1,[Whether we have xattr support])
 	SMB_ENABLE(XATTR,YES)
+elif test x"$ac_cv_func_ext_extattr_list_file" = x"yes"; then
+ 	AC_DEFINE(HAVE_EXTATTR_SUPPORT,1,[Whether we have extattr support])
+	SMB_ENABLE(XATTR,YES)
 fi
-
