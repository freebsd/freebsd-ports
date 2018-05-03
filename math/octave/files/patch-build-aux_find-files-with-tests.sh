--- build-aux/find-files-with-tests.sh.orig	2018-04-30 17:03:56 UTC
+++ build-aux/find-files-with-tests.sh
@@ -21,7 +21,7 @@
 set -e
 
 GREP=${GREP:-grep}
-SED=${SED:-sed}
+SED=gsed
 
 srcdir="$1"
 if [ "$1" ]; then
