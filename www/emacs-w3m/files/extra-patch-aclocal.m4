--- aclocal.m4.orig	2012-01-06 11:02:58.000000000 +0900
+++ aclocal.m4	2012-03-11 22:40:26.000000000 +0900
@@ -13,7 +13,7 @@
   dnl XEmacs 21.5 starts, in order to suppress warnings for Lisp shadows
   dnl when XEmacs 21.5 starts.
   if test "${VANILLA_FLAG}" = "-vanilla"; then
-	XEMACSDEBUG='XEMACSDEBUG='\''(setq log-warning-minimum-level (quote error))'\'' '
+	XEMACSDEBUG=
   else
 	XEMACSDEBUG=
   fi
@@ -263,6 +263,7 @@
       fi
     fi])
   retval=`eval ${XEMACSDEBUG}${EMACS}' '${VANILLA_FLAG}' -batch -l w3mhack.el '${ADDITIONAL_LOAD_PATH}' -f w3mhack-print-status 2>/dev/null | $EGREP -v '\''^$'\'`
+  retval=`echo $retval | tr -d "\n"`
   if test x"$retval" != xOK; then
     AC_MSG_ERROR([Process couldn't proceed.  See the above messages.])
   fi
