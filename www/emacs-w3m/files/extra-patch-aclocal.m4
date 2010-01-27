--- aclocal.m4.orig	2008-02-06 11:24:18.000000000 +0900
+++ aclocal.m4	2010-01-28 00:57:56.000000000 +0900
@@ -13,7 +13,7 @@
   dnl XEmacs 21.5 starts, in order to suppress warnings for Lisp shadows
   dnl when XEmacs 21.5 starts.
   if test "${VANILLA_FLAG}" = "-vanilla"; then
-	XEMACSDEBUG='XEMACSDEBUG='\''(setq log-warning-minimum-level (quote error))'\'' '
+	XEMACSDEBUG=
   else
 	XEMACSDEBUG=
   fi
@@ -296,6 +296,7 @@
       fi
     fi])
   retval=`eval ${XEMACSDEBUG}${EMACS}' '${VANILLA_FLAG}' -batch -l w3mhack.el '${ADDITIONAL_LOAD_PATH}' -f w3mhack-print-status'`
+  retval=`echo $retval | tr -d "\n"`
   if test x"$retval" != xOK; then
     AC_MSG_ERROR([Process couldn't proceed.  See the above messages.])
   fi
