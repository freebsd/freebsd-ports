--- gtk/build-intel-lib.sh.orig	2017-11-20 03:58:50 UTC
+++ gtk/build-intel-lib.sh
@@ -1,10 +1,10 @@
 #!/bin/sh
 if [ -f gcc111libbid.a ]; then exit 0; fi
-tar xvfz ../inteldecimal/IntelRDFPMathLib20U1.tar.gz
+#tar xvfz ../inteldecimal/IntelRDFPMathLib20U1.tar.gz
 cd IntelRDFPMathLib20U1
 patch -p0 <../intel-lib-linux.patch
 cd LIBRARY
-make CC=gcc CALL_BY_REF=1 GLOBAL_RND=1 GLOBAL_FLAGS=1 UNCHANGED_BINARY_FLAGS=0
+gmake CC=cc CALL_BY_REF=1 GLOBAL_RND=1 GLOBAL_FLAGS=1 UNCHANGED_BINARY_FLAGS=0
 mv libbid.a ../../gcc111libbid.a
 cd ../..
 ( echo '#ifdef FREE42_FPTEST'; echo 'const char *readtest_lines[] = {'; tr -d '\r' < IntelRDFPMathLib20U1/TESTS/readtest.in | sed 's/^\(.*\)$/"\1",/'; echo '0 };'; echo '#endif' ) > readtest_lines.cc
