--- build-aux/find-defun-files.sh.orig	2020-11-26 18:20:44 UTC
+++ build-aux/find-defun-files.sh
@@ -27,7 +27,7 @@
 
 set -e
 
-SED=${SED:-sed}
+SED=gsed
 EGREP=${EGREP:-egrep}
 
 # Some stupid egreps don't like empty elements in alternation patterns,
