--- src/3rdparty/chromium/base/functional/unretained_traits.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/functional/unretained_traits.h
@@ -90,7 +90,7 @@ struct SupportsUnretainedImpl {
 // official builds, and then in non-test code as well.
 #if defined(FORCE_UNRETAINED_COMPLETENESS_CHECKS_FOR_TESTS) || \
     (!defined(UNIT_TEST) && !defined(OFFICIAL_BUILD) &&        \
-     (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)))
+     (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)))
       static_assert(v,
                     "Argument requires unretained storage, but type is not "
                     "fully defined. This prevents determining whether "
