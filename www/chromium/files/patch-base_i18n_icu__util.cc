--- base/i18n/icu_util.cc.orig	2020-05-13 18:39:35 UTC
+++ base/i18n/icu_util.cc
@@ -49,7 +49,7 @@
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
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMECAST)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
   // See TimeZoneMonitorLinux::NotifyClientsFromImpl().
