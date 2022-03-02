--- base/rand_util.h.orig	2022-02-28 16:54:41 UTC
+++ base/rand_util.h
@@ -77,7 +77,7 @@ void RandomShuffle(Itr first, Itr last) {
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_OPENBSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
