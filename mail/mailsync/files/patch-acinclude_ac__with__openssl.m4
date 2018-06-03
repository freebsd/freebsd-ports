FreeBSD sh(1) does not support the Brace Expansion.

--- acinclude/ac_with_openssl.m4.orig	2018-05-22 07:38:01 UTC
+++ acinclude/ac_with_openssl.m4
@@ -3,7 +3,7 @@ dnl Output:
 dnl AC_SUBST: @OPENSSL_INCLUDES@ @OPENSSL_LDFLAGS@ @OPENSSL_LIBS@
 dnl AM_CONDITIONAL: HAVE_OPENSSL
 AC_DEFUN(AC_WITH_OPENSSL,[
- OPENSSLLOCATIONS="/usr,/usr/local,/usr/local/openssl,/opt/openssl,/usr/local/ssl,/usr/lib/ssl,/usr/ssl"
+ OPENSSLLOCATIONS=""
  HAVE_OPENSSL="no"
  OPENSSL_LDFLAGS=""
  OPENSSL_LIBS=""
@@ -14,7 +14,7 @@ AC_DEFUN(AC_WITH_OPENSSL,[
    if test "$withval" = "no" ; then
     OPENSSLLOCATIONS=""
    else
-    test "$withval" = "yes" || OPENSSLLOCATIONS="$withval,${OPENSSLLOCATIONS}"
+    test "$withval" = "yes" || OPENSSLLOCATIONS="$withval"
    fi
   ]
  )
@@ -22,13 +22,12 @@ AC_DEFUN(AC_WITH_OPENSSL,[
   ifelse([$2], , :, [$2])
  else
   AC_MSG_CHECKING([for libssl])
-  for p in `eval "echo {${OPENSSLLOCATIONS}}{/lib,/lib64}"` ; do
+  p=${OPENSSLLOCATIONS}/lib
    if test -r "${p}/libssl.a" -o -r "${p}/libssl.so" ; then
     OPENSSL_LDFLAGS="-L${p}"
     AC_MSG_RESULT([found in ${p}])
     break
    fi
-  done
   if test -z "${OPENSSL_LDFLAGS}" ; then
    AC_MSG_RESULT([not found])
    ifelse([$2], , :, [$2])
@@ -50,13 +49,12 @@ AC_DEFUN(AC_WITH_OPENSSL,[
     ifelse([$2], , :, [$2])
    else
     AC_MSG_CHECKING([for openssl/ssl.h])
-    for p in `eval "echo {${OPENSSLLOCATIONS}}{/include,}"` ; do
+    p=${OPENSSLLOCATIONS}/include
      if test -r "${p}/openssl/ssl.h" ; then
       OPENSSL_INCLUDES="-I${p}"
       AC_MSG_RESULT([found in ${p}])
       break
      fi
-    done
     if test -z "${OPENSSL_INCLUDES}" ; then
      AC_MSG_RESULT([not found])
      ifelse([$2], , :, [$2])
