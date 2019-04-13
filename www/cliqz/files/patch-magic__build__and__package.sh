Disable build and packaging of tests.

--- magic_build_and_package.sh.orig	2019-04-03 08:46:52 UTC
+++ magic_build_and_package.sh
@@ -1,4 +1,4 @@
-#! /bin/bash
+#! /usr/local/bin/bash
 
 # Optional ENVs:
 #  CQZ_BUILD_ID - specify special build timestamp or use latest one (depend on channel)
@@ -43,8 +43,8 @@ fi
 echo '***** Building *****'
 ./mach build
 
-echo '***** Building tests *****'
-./mach build package-tests
+#echo '***** Building tests *****'
+#./mach build package-tests
 
 echo '***** Packaging *****'
 ./mach package
