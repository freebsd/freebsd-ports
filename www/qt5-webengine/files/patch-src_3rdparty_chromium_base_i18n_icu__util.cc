--- src/3rdparty/chromium/base/i18n/icu_util.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/base/i18n/icu_util.cc
@@ -20,7 +20,7 @@
 #include "build/build_config.h"
 #include "third_party/icu/source/common/unicode/putil.h"
 #include "third_party/icu/source/common/unicode/udata.h"
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_ANDROID)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)) || defined(OS_ANDROID)
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
 
@@ -68,7 +68,11 @@ wchar_t g_debug_icu_pf_filename[_MAX_PATH];
 // No need to change the filename in multiple places (gyp files, windows
 // build pkg configurations, etc). 'l' stands for Little Endian.
 // This variable is exported through the header file.
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
 const char kIcuDataFileName[] = "icudtl.dat";
+#else
+const char kIcuDataFileName[] = "icudtb.dat";
+#endif
 #if defined(OS_ANDROID)
 const char kAndroidAssetsIcuDataFileName[] = "assets/icudtl.dat";
 #endif
@@ -290,7 +294,7 @@ bool InitializeICU() {
 // TODO(jungshik): Some callers do not care about tz at all. If necessary,
 // add a boolean argument to this function to init'd the default tz only
 // when requested.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (result)
     std::unique_ptr<icu::TimeZone> zone(icu::TimeZone::createDefault());
 #endif
