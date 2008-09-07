--- ./build/build_all.sh.orig	2008-08-26 15:14:49.000000000 +0900
+++ ./build/build_all.sh	2008-09-07 01:09:10.000000000 +0900
@@ -100,6 +100,7 @@
         ./configure \
             --prefix=${WORK}/tmp_install \
             --enable-threads \
+            --mandir=${PREFIX}/man \
             ${CONFIGURE_OPTION} && \
         ${MAKE_CMD} && \
         ${MAKE_CMD} install
@@ -135,6 +136,7 @@
         cd ../ && \
         ./configure \
             --prefix=${PREFIX} \
+            --mandir=${PREFIX}/man \
             --with-libmilter=${WORK}/tmp_install \
             --with-libbind=${WORK}/tmp_install \
             ${CONFIGURE_OPTION} && \
