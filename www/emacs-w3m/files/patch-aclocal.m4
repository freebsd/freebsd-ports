--- aclocal.m4.orig	2019-04-20 15:06:07 UTC
+++ aclocal.m4
@@ -27,10 +27,10 @@ fi
 AC_CACHE_VAL(EMACS_cv_SYS_$1,[
 	OUTPUT=./conftest-$$
 	EL=./conftest-$$.el
-	echo "(let ((x ${elisp})) (write-region (format \"%s\" x) nil \"${OUTPUT}\" nil 5) (delete-file \"${EL}\"))" >& ${EL} 2>&1
-	eval "${XEMACSDEBUG} '${EMACS}' ${VANILLA_FLAG} -batch -l ${EL}" >& AC_FD_CC 2>&1
+	echo "(let ((x ${elisp})) (write-region (format \"%s\" x) nil \"${OUTPUT}\" nil 5) (delete-file \"${EL}\"))" > ${EL} 2>&1
+	eval "${XEMACSDEBUG} '${EMACS}' ${VANILLA_FLAG} -batch -l ${EL}" > AC_FD_CC 2>&1
 	retval="`cat ${OUTPUT}`"
-	echo "=> ${retval}" >& AC_FD_CC 2>&1
+	echo "=> ${retval}" > AC_FD_CC 2>&1
 	rm -f ${OUTPUT}
 	EMACS_cv_SYS_$1="${retval}"
 ])
