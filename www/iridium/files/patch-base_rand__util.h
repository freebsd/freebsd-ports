--- base/rand_util.h.orig	2022-03-28 18:11:04 UTC
+++ base/rand_util.h
@@ -77,7 +77,7 @@ void RandomShuffle(Itr first, Itr last) {
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_OPENBSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
