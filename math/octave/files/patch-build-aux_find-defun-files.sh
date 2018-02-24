--- build-aux/find-defun-files.sh.orig	2017-02-22 17:15:26 UTC
+++ build-aux/find-defun-files.sh
@@ -2,7 +2,7 @@
 
 set -e
 
-SED=${SED:-sed}
+SED=gsed
 EGREP=${EGREP:-egrep}
 
 # Some stupid egreps don't like empty elements in alternation patterns,
