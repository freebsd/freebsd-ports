--- build.sh.orig	2025-03-20 16:46:21 UTC
+++ build.sh
@@ -124,5 +124,6 @@ if [ $shared ]; then
     esac
     (set -x; ${CC} -shared -o $sharedlib \
                    -Wl,--whole-archive,libblst.a,--no-whole-archive ${CFLAGS} \
+		   -Wl,--soname=${sharedlib} \
                    -Wl,-Bsymbolic)
 fi
