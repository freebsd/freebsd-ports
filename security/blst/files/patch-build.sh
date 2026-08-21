--- build.sh.orig	2026-07-24 13:48:23 UTC
+++ build.sh
@@ -129,5 +129,5 @@ if [ $shared ]; then
                 CFLAGS="${CFLAGS} -Wl,-Bsymbolic";;
     esac
     (set -x; ${CC} -shared -o $sharedlib \
-                   -Wl,--whole-archive,libblst.a,--no-whole-archive ${CFLAGS})
+                   -Wl,--soname=${sharedlib} -Wl,--whole-archive,libblst.a,--no-whole-archive ${CFLAGS})
 fi
