--- build-aux/get-source-mtime.sh.orig	2023-03-09 00:21:26 UTC
+++ build-aux/get-source-mtime.sh
@@ -34,7 +34,7 @@
 set -e
 
 PERL=${PERL:-perl}
-SED=${SED:-sed}
+SED=gsed
 
 if [ $# -ne 1 ]; then
   echo "usage: get-source-mtime.sh SRCDIR" 1>&2
