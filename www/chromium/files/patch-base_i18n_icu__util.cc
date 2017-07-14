--- base/i18n/icu_util.cc.orig	2017-06-09 16:50:47.670684000 +0200
+++ base/i18n/icu_util.cc	2017-06-09 16:52:10.911955000 +0200
@@ -20,7 +20,7 @@
 #include "build/build_config.h"
 #include "third_party/icu/source/common/unicode/putil.h"
 #include "third_party/icu/source/common/unicode/udata.h"
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
 
@@ -298,7 +298,7 @@
 // TODO(jungshik): Some callers do not care about tz at all. If necessary,
 // add a boolean argument to this function to init'd the default tz only
 // when requested.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (result)
     std::unique_ptr<icu::TimeZone> zone(icu::TimeZone::createDefault());
 #endif
