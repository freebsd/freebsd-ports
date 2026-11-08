--- autogen.sh.orig	2026-09-20 13:59:40 UTC
+++ autogen.sh
@@ -3,5 +3,3 @@ ${AUTORECONF:-autoreconf} --force --install "$@"
 set -e
 
 ${AUTORECONF:-autoreconf} --force --install "$@"
-cd sigscheme
-./autogen.sh "$@"
