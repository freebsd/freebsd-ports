FreeBSD sh(1) does not support the Brace Expansion.

--- acinclude/ac_with_cclient.m4.orig	2018-05-22 07:37:52 UTC
+++ acinclude/ac_with_cclient.m4
@@ -3,7 +3,7 @@ dnl Output:
 dnl AC_SUBST: @CCLIENT_INCLUDES@ @CCLIENT_LIBS@ @CCLIENT_CXXFLAGS@
 dnl AM_CONDITIONAL: HAVE_CCLIENT
 AC_DEFUN(AC_WITH_CCLIENT,[
- CCLIENTLOCATIONS="/usr,/usr/local"
+ CCLIENTLOCATIONS=""
  HAVE_CCLIENT="no"
  CCLIENT_LIBS=""
  CCLIENT_INCLUDES=""
@@ -16,7 +16,7 @@ AC_DEFUN(AC_WITH_CCLIENT,[
    if test "$withval" = "no" ; then
     CCLIENTLOCATIONS=""
    else
-    test "$withval" = "yes" || CCLIENTLOCATIONS="$withval,${CCLIENTLOCATIONS}"
+    test "$withval" = "yes" || CCLIENTLOCATIONS="$withval"
    fi
   ]
  )
@@ -28,7 +28,7 @@ AC_DEFUN(AC_WITH_CCLIENT,[
   dnl Looking for headers c-client headers
   dnl
    AC_MSG_CHECKING([for c-client.h])
-  for p in `eval "echo {${CCLIENTLOCATIONS}}{,/c-client,/lib/c-client,/include/c-client,/include,/include/imap}"` ; do
+  p=${CCLIENTLOCATIONS}/include/c-client
    if test -r "${p}/c-client.h" -a -r "${p}/linkage.h" -a -r "${p}/linkage.c" ; then
     CCLIENT_INCLUDES="-I${p}"
     CCLIENT_LINKAGE_H="${p}/linkage.h"
@@ -36,7 +36,6 @@ AC_DEFUN(AC_WITH_CCLIENT,[
     AC_MSG_RESULT([found in ${p}])
     break
    fi
-  done
   if test -z "${CCLIENT_INCLUDES}" ; then
    AC_MSG_RESULT([not found])
    ifelse([$2], , :, [$2])
@@ -48,13 +47,12 @@ AC_DEFUN(AC_WITH_CCLIENT,[
    dnl Looking for c-client libraries
    dnl
    AC_MSG_CHECKING([for c-client library])
-   for l in `eval "echo {${CCLIENTLOCATIONS}}{,/c-client,/lib/c-client,/lib,/lib64}/{libc-client,libc-client4,c-client}{${SOP}}"` ; do
+   l=${CCLIENTLOCATIONS}/lib/libc-client.so
     if test -r "$l" ; then
      AC_MSG_RESULT([found ${l}])
      CCLIENT_LIBS="$l"
      break
     fi
-   done
    if test -z "${CCLIENT_LIBS}" ; then
     AC_MSG_RESULT([not found])
     ifelse([$2], , :, [$2])
