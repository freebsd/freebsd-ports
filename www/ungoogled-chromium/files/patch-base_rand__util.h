--- base/rand_util.h.orig	2025-01-25 09:34:31 UTC
+++ base/rand_util.h
@@ -141,7 +141,7 @@ void RandomShuffle(Itr first, Itr last) {
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
