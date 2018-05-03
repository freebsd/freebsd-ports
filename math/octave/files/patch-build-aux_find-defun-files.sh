--- build-aux/find-defun-files.sh.orig	2018-04-30 17:03:56 UTC
+++ build-aux/find-defun-files.sh
@@ -20,7 +20,7 @@
 
 set -e
 
-SED=${SED:-sed}
+SED=gsed
 EGREP=${EGREP:-egrep}
 
 # Some stupid egreps don't like empty elements in alternation patterns,
