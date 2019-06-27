--- common_power.h.orig	2019-06-26 10:25:04 UTC
+++ common_power.h
@@ -499,7 +499,7 @@ static inline int blas_quickdivide(blasint x, blasint 
 
 #if defined(ASSEMBLER) && !defined(NEEDPARAM)
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #ifndef __64BIT__
 #define PROLOGUE \
 	.section .text;\
@@ -774,7 +774,7 @@ Lmcount$lazy_ptr:
 
 #define HALT		mfspr	r0, 1023
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #if defined(PPC440) || defined(PPC440FP2)
 #undef  MAX_CPU_NUMBER
 #define MAX_CPU_NUMBER 1
@@ -819,7 +819,7 @@ Lmcount$lazy_ptr:
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #ifndef __64BIT__
 #define FRAMESLOT(X) (((X) * 4) + 8)
 #else
