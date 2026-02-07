--- share/mk/bsd.own.mk.orig	2025-08-10 13:11:16 UTC
+++ share/mk/bsd.own.mk
@@ -17,7 +17,7 @@ CLANG_ARCH=aarch64 amd64 arm i386 mips64 mips64el powe
 
 CLANG_ARCH=aarch64 amd64 arm i386 mips64 mips64el powerpc powerpc64 riscv64 sparc64
 # BEGIN FreeBSD-relayd
-CLANG_ARCH=aarch64 amd64 arm armv6 armv7 i386 mips64 mips64el powerpc powerpc64 riscv64 sparc64
+CLANG_ARCH=aarch64 amd64 arm armv6 armv7 i386 mips64 mips64el powerpc powerpc64 powerpc64le riscv64
 # END FreeBSD-relayd
 GCC4_ARCH=alpha hppa sh sparc64
 GCC3_ARCH=m88k
