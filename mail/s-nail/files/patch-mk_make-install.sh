--- mk/make-install.sh.orig	2019-09-03 03:03:54 UTC
+++ mk/make-install.sh
@@ -32,7 +32,7 @@ __copychownfile() {
 __stripfile() {
    _file=${1}
    if [ "${OPT_DEBUG}" != 0 ]; then :;
-   elif [ -n "${HAVE_STRIP}" ]; then
+   elif [ "x${strip}" != "x" ]; then
       ${strip} "${_file}"
    fi
 }
