--- config/knl/make_defs.mk.orig	2022-04-01 13:12:06 UTC
+++ config/knl/make_defs.mk
@@ -81,7 +81,7 @@ ifeq ($(CC_VENDOR),clang)
 CKVECFLAGS     := -xMIC-AVX512
 else
 ifeq ($(CC_VENDOR),clang)
-CKVECFLAGS     := -mavx512f -mavx512pf -mfpmath=sse -march=knl
+CKVECFLAGS     := -mavx512f -mfpmath=sse -march=knl
 else
 $(error gcc, icc, or clang is required for this configuration.)
 endif
@@ -105,7 +105,7 @@ ifeq ($(CC_VENDOR),clang)
 CRVECFLAGS     := -xMIC-AVX512
 else
 ifeq ($(CC_VENDOR),clang)
-CRVECFLAGS     := -march=knl -mno-avx512f -mno-avx512pf -mno-avx512er -mno-avx512cd -funsafe-math-optimizations -ffp-contract=fast
+CRVECFLAGS     := -march=knl -mno-avx512f -mno-avx512cd -funsafe-math-optimizations -ffp-contract=fast
 else
 $(error gcc, icc, or clang is required for this configuration.)
 endif
