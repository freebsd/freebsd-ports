--- m4/gssapi.m4.orig	Wed Apr 17 19:05:04 2002
+++ m4/gssapi.m4	Mon Oct 16 10:59:34 2006
@@ -6,10 +6,13 @@
 dnl if it is set and not "yes".
 dnl Defines GSSAPI_CFLAGS and GSSAPI_LIBS if found.
 dnl Defines GSSAPI_IMPL to "Heimdal", "MIT", or "OldMIT", or "none" if not found
-AC_DEFUN(MUTT_AM_PATH_GSSAPI,
+AC_DEFUN([MUTT_AM_PATH_GSSAPI],
 [
   GSSAPI_PREFIX=[$]$1
   GSSAPI_IMPL="none"
+  saved_CPPFLAGS="$CPPFLAGS"
+  saved_LDFLAGS="$LDFLAGS"
+  saved_LIBS="$LIBS"
   dnl First try krb5-config
   if test "$GSSAPI_PREFIX" != "yes"
   then
@@ -24,14 +27,11 @@
     GSSAPI_LIBS="$MUTTLIBS `$KRB5CFGPATH --libs gssapi`"
     case "`$KRB5CFGPATH --version`" in
       "Kerberos 5 "*)	GSSAPI_IMPL="MIT";;
-      [hH]eimdal*)		GSSAPI_IMPL="Heimdal";;
+      ?eimdal*)		GSSAPI_IMPL="Heimdal";;
       *)		GSSAPI_IMPL="Unknown";;
    esac
   else
     dnl No krb5-config, run the old code
-    saved_CPPFLAGS="$CPPFLAGS"
-    saved_LDFLAGS="$LDFLAGS"
-    saved_LIBS="$LIBS"
     if test "$GSSAPI_PREFIX" != "yes"
     then
       GSSAPI_CFLAGS="-I$GSSAPI_PREFIX/include"
