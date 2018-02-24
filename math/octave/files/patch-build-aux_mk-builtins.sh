--- build-aux/mk-builtins.sh.orig	2017-02-22 18:01:55 UTC
+++ build-aux/mk-builtins.sh
@@ -20,7 +20,7 @@
 
 set -e
 
-SED=${SED:-sed}
+SED=gsed
 
 defun_dld_are_built_in=false
 make_header=false
