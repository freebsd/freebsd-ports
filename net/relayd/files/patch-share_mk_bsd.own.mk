--- share/mk/bsd.own.mk.orig	2023-11-02 07:25:02 UTC
+++ share/mk/bsd.own.mk
@@ -15,7 +15,7 @@ SKEY?=		yes
 # Set `YP' to `yes' to build with support for NIS/YP.
 YP?=		yes
 
-CLANG_ARCH=aarch64 amd64 arm i386 mips64 mips64el powerpc powerpc64 riscv64 sparc64
+CLANG_ARCH=aarch64 amd64 arm armv6 armv7 i386 mips64 mips64el powerpc powerpc64 riscv64 sparc64
 GCC4_ARCH=alpha hppa sh sparc64
 GCC3_ARCH=m88k
 LLD_ARCH=aarch64 amd64 arm i386 powerpc powerpc64 riscv64
