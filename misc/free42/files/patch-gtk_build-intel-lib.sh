--- gtk/build-intel-lib.sh.orig	2021-03-30 03:08:43 UTC
+++ gtk/build-intel-lib.sh
@@ -43,6 +43,8 @@ fi
 
 tar xvfz ../inteldecimal/IntelRDFPMathLib20U1.tar.gz
 cd IntelRDFPMathLib20U1
+sed -i '' -e 's/\r//g' LIBRARY/src/bid_functions.h
+patch -p0 <../intel-lib-freebsd.patch
 patch -p0 <../intel-lib-linux.patch
 
 # When building for architectures other than x86 or x86_64, I remove the
@@ -55,11 +57,11 @@ patch -p0 <../intel-lib-linux.patch
 # it to x86_64 works when targeting arm64, a 64-bit platform.
 # Of course, proceed with caution. Your mileage may vary.
 
-case `uname -m` in
-  armv7|armv7l|i386|ppc)
+case `uname -p` in
+  armv6|armv7|armv7l|i386|ppc|powerpc|powerpcspe|mips)
     patch -p0 <../intel-lib-unknown-32bit.patch
     ;;
-  aarch64|arm64|i86pc)
+  aarch64|arm64|i86pc|powerpc64|powerpc64le|mips64|riscv64)
     patch -p0 <../intel-lib-unknown-64bit.patch
     ;;
 esac
