--- munchlist.X.orig	Sun Apr 21 16:52:41 2002
+++ munchlist.X	Sun Apr 21 16:53:03 2002
@@ -160,7 +160,7 @@
     set -vx
 fi
 LIBDIR=!!LIBDIR!!
-TDIR=${TMPDIR-/usr/tmp}
+TDIR=${TMPDIR-/tmp}
 TMP=${TDIR}/munch$$
 SORTTMP="-T ${TDIR}"			# !!SORTTMP!!
 
