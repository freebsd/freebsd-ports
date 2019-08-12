--- base/i18n/icu_util.cc.orig	2019-07-24 18:58:02 UTC
+++ base/i18n/icu_util.cc
@@ -20,7 +20,7 @@
 #include "build/build_config.h"
 #include "third_party/icu/source/common/unicode/putil.h"
 #include "third_party/icu/source/common/unicode/udata.h"
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_ANDROID)
+#if (defined(OS_LINUX) || defined(OS_BSD) && !defined(OS_CHROMEOS)) || defined(OS_ANDROID)
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
 
@@ -285,7 +285,7 @@ bool InitializeICU() {
 // TODO(jungshik): Some callers do not care about tz at all. If necessary,
 // add a boolean argument to this function to init'd the default tz only
 // when requested.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (result)
     std::unique_ptr<icu::TimeZone> zone(icu::TimeZone::createDefault());
 #endif
