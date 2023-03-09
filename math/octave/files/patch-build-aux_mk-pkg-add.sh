--- build-aux/mk-pkg-add.sh.orig	2023-03-09 00:21:26 UTC
+++ build-aux/mk-pkg-add.sh
@@ -31,7 +31,7 @@ export LC_ALL
 
 set -e
 
-SED=${SED:-sed}
+SED=gsed
 
 srcdir="$1"
 shift
