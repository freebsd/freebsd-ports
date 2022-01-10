--- src/include/cdfdist.h.orig	2019-10-16 16:22:18 UTC
+++ src/include/cdfdist.h
@@ -135,7 +135,7 @@
 #  define unix
 #endif
 
-#if defined(__arm__)
+#if defined(__arm__) || defined (__aarch64__)
 #  define ARM
 #  if defined(__BYTE_ORDER__)
 #     if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
@@ -567,7 +567,7 @@ typedef sChar sByte;
 #      if defined(__DARWIN_64_BIT_INO_T)
 #         define STAT     stat
 #      else
-#         define STAT     stat64
+#         define STAT     stat
 #      endif
 #    endif
 #  endif
