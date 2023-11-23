--- src/3rdparty/chromium/base/functional/unretained_traits.h.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/base/functional/unretained_traits.h
@@ -130,7 +130,7 @@ struct TypeSupportsUnretained {
 // official builds, and then in non-test code as well.
 #if !defined(UNIT_TEST) && !defined(OFFICIAL_BUILD)
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    defined(FORCE_UNRETAINED_COMPLETENESS_CHECKS_FOR_TESTS)
+    BUILDFLAG(IS_BSD) || defined(FORCE_UNRETAINED_COMPLETENESS_CHECKS_FOR_TESTS)
   static_assert(IsCompleteTypeV<T> ||
                     IsIncompleteTypeSafeForUnretained<std::remove_cv_t<T>>,
                 "T must be fully defined.");
