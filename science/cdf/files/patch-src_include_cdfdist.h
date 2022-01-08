--- src/include/cdfdist.h.orig	2022-01-08 02:20:38 UTC
+++ src/include/cdfdist.h
@@ -567,7 +567,7 @@ typedef sChar sByte;
 #      if defined(__DARWIN_64_BIT_INO_T)
 #         define STAT     stat
 #      else
-#         define STAT     stat64
+#         define STAT     stat
 #      endif
 #    endif
 #  endif
