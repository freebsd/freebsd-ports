--- base/rand_util.h.orig	2026-02-11 09:05:39 UTC
+++ base/rand_util.h
@@ -222,7 +222,7 @@ decltype(auto) RandomChoice(Range&& r) {
   return r[base::RandGenerator(r.size())];
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
