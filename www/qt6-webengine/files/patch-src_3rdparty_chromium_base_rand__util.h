--- src/3rdparty/chromium/base/rand_util.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/rand_util.h
@@ -81,7 +81,7 @@ void RandomShuffle(Itr first, Itr last) {
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_OPENBSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
