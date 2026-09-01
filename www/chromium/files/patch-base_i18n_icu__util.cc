--- base/i18n/icu_util.cc.orig	2026-08-31 10:59:09 UTC
+++ base/i18n/icu_util.cc
@@ -57,7 +57,7 @@
 #include "third_party/icu/source/common/unicode/unistr.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
@@ -331,7 +331,7 @@ void InitializeIcuTimeZone() {
       FuchsiaIntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif BUILDFLAG(IS_CHROMEOS) || \
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_ANDROID)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
