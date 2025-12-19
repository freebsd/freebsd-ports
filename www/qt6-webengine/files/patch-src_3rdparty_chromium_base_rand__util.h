--- src/3rdparty/chromium/base/rand_util.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/rand_util.h
@@ -209,7 +209,7 @@ void RandomShuffle(Itr first, Itr last) {
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
