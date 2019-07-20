--- aclocal.m4.orig	2019-07-18 23:39:24 UTC
+++ aclocal.m4
@@ -11,11 +11,11 @@ fi
 AC_CACHE_VAL(EMACS_cv_SYS_$1,[
 	OUTPUT=./conftest-$$
 	EL=./conftest-$$.el
-	echo "(let ((x ${elisp})) (write-region (format \"%s\" x) nil \"${OUTPUT}\" nil 5) (delete-file \"${EL}\"))" >& ${EL} 2>&1
-	eval "'${EMACS}' ${VANILLA_FLAG} -batch -l ${EL}" >& AC_FD_CC 2>&1
+	echo "(let ((x ${elisp})) (write-region (format \"%s\" x) nil \"${OUTPUT}\" nil 5) (delete-file \"${EL}\"))" > ${EL} 2>&1
+	eval "'${EMACS}' ${VANILLA_FLAG} -batch -l ${EL}" > AC_FD_CC 2>&1
 	if test -f ${OUTPUT}; then
 		retval="`cat ${OUTPUT}`"
-		echo "=> ${retval}" >& AC_FD_CC 2>&1
+		echo "=> ${retval}" > AC_FD_CC 2>&1
 		rm -f ${OUTPUT}
 		EMACS_cv_SYS_$1="${retval}"
 	fi])
