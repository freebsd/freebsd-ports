--- build-aux/find-files-with-tests.sh.orig	2017-02-22 18:01:55 UTC
+++ build-aux/find-files-with-tests.sh
@@ -21,7 +21,7 @@
 set -e
 
 GREP=${GREP:-grep}
-SED=${SED:-sed}
+SED=gsed
 
 srcdir="$1"
 if [ "$1" ]; then
