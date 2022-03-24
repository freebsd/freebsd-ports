--- tests/cert-tests/pkcs12.sh.orig	2022-03-02 11:38:09 UTC
+++ tests/cert-tests/pkcs12.sh
@@ -150,9 +150,9 @@ EOF
 
 EOF
 
-sed -n '/^\(MAC\|BAG\)/,/^$/p' ${TMPFILE_PEM} | \
+sed -n -r '/^(MAC|BAG)/,/^$/p' ${TMPFILE_PEM} | \
 sed -e '/^[ 	]*Salt:/d' \
-    -e '/^BAG #[0-9]*/,$ { /^[ 	]*Salt size:/d }' > ${INFO_OUT}
+    -e '/^BAG #[0-9]*/,$ { /^[ 	]*Salt size:/d; }' > ${INFO_OUT}
 
 diff ${INFO_EXP} ${INFO_OUT}
 
