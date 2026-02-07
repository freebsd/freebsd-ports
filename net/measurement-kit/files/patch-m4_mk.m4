--- m4/mk.m4.orig	2021-03-04 14:14:57 UTC
+++ m4/mk.m4
@@ -99,8 +99,10 @@ AC_DEFUN([MK_AM_OPENSSL], [
                 [SSL toolkit @<:@default=check@:>@])
               ],
               [
-                CPPFLAGS="$CPPFLAGS -I$withval/include"
-                LDFLAGS="$LDFLAGS -L$withval/lib"
+		if test ${with_openssl} != /usr; then
+                  CPPFLAGS="$CPPFLAGS -I$withval/include"
+                  LDFLAGS="$LDFLAGS -L$withval/lib"
+		fi
               ],
               [
                 if test -d /usr/local/Cellar/openssl@1.1; then
@@ -252,43 +254,8 @@ dnl
 dnl Except as contained in this notice, the name of a copyright holder shall not be
 dnl used in advertising or otherwise to promote the sale, use or other dealings in
 dnl this Software without prior written authorization of the copyright holder.
-AC_DEFUN([MK_MAYBE_CA_BUNDLE], [
-  AC_MSG_CHECKING([CA bundle path])
-  AC_ARG_WITH([ca-bundle], AC_HELP_STRING([--with-ca-bundle=FILE],
-               [Path to CA bundle]), [want_ca="$withval"], [want_ca="unset"])
-  if test "x$want_ca" != "xunset"; then
-    ca="$want_ca"
-  else
-    ca="no"
-    if test "x$cross_compiling" != "xyes"; then
-        for a in /etc/ssl/certs/ca-certificates.crt                            \
-                 /etc/pki/tls/certs/ca-bundle.crt                              \
-                 /usr/share/ssl/certs/ca-bundle.crt                            \
-                 /usr/local/share/certs/ca-root.crt                            \
-                 /etc/ssl/cert.pem                                             \
-                 /usr/local/etc/openssl/cert.pem; do
-          if test -f "$a"; then
-            ca="$a"
-            break
-          fi
-        done
-    fi
-  fi
-  if test "x$ca" != "xno"; then
-    MK_CA_BUNDLE="$ca"
-    AC_DEFINE_UNQUOTED(MK_CA_BUNDLE, "$ca", [Location of default ca bundle])
-    AC_SUBST(MK_CA_BUNDLE)
-    AC_MSG_RESULT([$ca])
-  elif test "x$cross_compiling" == "xyes"; then
-    AC_MSG_RESULT([skipped (cross compiling)])
-    AC_MSG_WARN([skipped the ca-bundle detection when cross-compiling])
-    AC_DEFINE_UNQUOTED(MK_CA_BUNDLE, "", [Location of default ca bundle])
-    AC_SUBST(MK_CA_BUNDLE)
-  else
-    AC_MSG_RESULT([no])
-    AC_MSG_ERROR([you should give a ca-bundle location])
-  fi
-])
+AC_DEFINE_UNQUOTED(MK_CA_BUNDLE, "", [Location of default ca bundle])
+AC_SUBST(MK_CA_BUNDLE)
 
 AC_DEFUN([MK_PTHREAD], [
   AX_PTHREAD
