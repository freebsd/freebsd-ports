--- build/m4/aircrack_ng_pcre.m4.orig	2018-12-09 22:53:44 UTC
+++ build/m4/aircrack_ng_pcre.m4
@@ -38,6 +38,10 @@ dnl If you delete this exception statement from all so
 dnl program, then also delete it here.
 
 AC_DEFUN([AIRCRACK_NG_PCRE], [
+
+AC_ARG_ENABLE([pcre],
+    AS_HELP_STRING([--disable-pcre],[Disable PCRE (libpcre).]))
+
 AC_ARG_ENABLE(static-pcre,
     AS_HELP_STRING([--enable-static-pcre],
 		[Enable statically linked PCRE libpcre.]),
@@ -52,7 +56,9 @@ if test "x$static_pcre" != "xno"; then
 		HAVE_PCRE=no
 	fi
 else
+    if test x$enable_pcre != xno; then
 	PKG_CHECK_MODULES(PCRE, libpcre, HAVE_PCRE=yes, HAVE_PCRE=no)
+    fi
 fi
 
 AS_IF([test "x$HAVE_PCRE" = "xyes"], [
