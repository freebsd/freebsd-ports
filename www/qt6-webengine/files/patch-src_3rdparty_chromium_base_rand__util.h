--- src/3rdparty/chromium/base/rand_util.h.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/base/rand_util.h
@@ -117,7 +117,7 @@ void RandomShuffle(Itr first, Itr last) {
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
