--- common_power.h.orig	2017-07-24 04:03:35 UTC
+++ common_power.h
@@ -241,7 +241,7 @@ static inline int blas_quickdivide(blasint x, blasint 
 #define HAVE_PREFETCH
 #endif
 
-#if defined(POWER3) || defined(POWER6) || defined(PPCG4) || defined(CELL) || defined(POWER8)
+#if defined(POWER3) || defined(POWER6) || defined(PPCG4) || defined(CELL) || defined(POWER8) || defined(PPC970)
 #define DCBT_ARG	0
 #else
 #define DCBT_ARG	8
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
