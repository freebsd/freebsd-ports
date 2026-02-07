--- autogen.sh.orig	2025-02-23 08:00:09 UTC
+++ autogen.sh
@@ -3,9 +3,6 @@ ${AUTORECONF:-autoreconf} --force --install "$@"
 set -e
 
 ${AUTORECONF:-autoreconf} --force --install "$@"
-# WORKAROUND: intltool-merge creates .intltool-merge-cache.lock but
-# it's not listed in mostlyclean in po/Makefile.in.in. It causes a
-# "make distcheck" failure.
-sed -i.bak -e 's/ \.intltool-merge-cache$/ .intltool-merge-cache{,.lock}/g' \
-  po/Makefile.in.in
-rm -f po/Makefile.in.in.bak
+if command -v intltoolize >/dev/null; then
+    intltoolize --copy --force --automake
+fi
