--- src/3rdparty/chromium/base/rand_util.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/base/rand_util.h
@@ -117,7 +117,7 @@ void RandomShuffle(Itr first, Itr last) {
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
