--- src/include/cdfdist.h.orig	2025-09-11 12:24:45 UTC
+++ src/include/cdfdist.h
@@ -137,7 +137,7 @@
 #  define unix
 #endif
 
-#if defined(__arm__) || defined(__arm64__) || \
+#if defined(__arm__) || defined(__arm64__) || defined (__aarch64__) || \
     (defined(__ARM_ARCH) && __ARM_ARCH > 0)
 /* linux(gcc)-based or clang-based */
 #  define ARM
@@ -594,7 +594,7 @@ typedef sChar sByte;
 #      if defined(__DARWIN_64_BIT_INO_T)
 #         define STAT     stat
 #      else
-#         define STAT     stat64
+#         define STAT     stat
 #      endif
 #    endif
 #  endif
