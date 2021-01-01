--- base/i18n/icu_util.cc.orig	2020-03-16 18:40:27 UTC
+++ base/i18n/icu_util.cc
@@ -46,7 +46,7 @@
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
 
@@ -341,7 +341,7 @@ void InitializeIcuTimeZone() {
       fuchsia::IntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST)
+#elif (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
   // To respond to the timezone change properly, the default timezone
   // cache in ICU has to be populated on starting up.
   // See TimeZoneMonitorLinux::NotifyClientsFromImpl().
