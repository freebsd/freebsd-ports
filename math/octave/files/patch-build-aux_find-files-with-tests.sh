--- build-aux/find-files-with-tests.sh.orig	2020-11-26 18:20:44 UTC
+++ build-aux/find-files-with-tests.sh
@@ -28,7 +28,7 @@
 set -e
 
 GREP=${GREP:-grep}
-SED=${SED:-sed}
+SED=gsed
 
 srcdir="$1"
 if [ "$1" ]; then
