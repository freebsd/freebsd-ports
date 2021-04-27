--- third_party/pdfium/xfa/fxfa/parser/cxfa_timezoneprovider.cpp.orig	2021-04-23 14:32:47 UTC
+++ third_party/pdfium/xfa/fxfa/parser/cxfa_timezoneprovider.cpp
@@ -11,6 +11,9 @@
 #include "build/build_config.h"
 
 static bool g_bProviderTimeZoneSet = false;
+#if defined(OS_BSD)
+static long g_lTimeZoneOffset = 0;
+#endif
 
 CXFA_TimeZoneProvider::CXFA_TimeZoneProvider() {
 #if defined(OS_WIN)
@@ -20,6 +23,18 @@ CXFA_TimeZoneProvider::CXFA_TimeZoneProvider() {
   }
   m_tz.tzHour = static_cast<int8_t>(_timezone / 3600 * -1);
   m_tz.tzMinute = static_cast<int8_t>((abs(_timezone) % 3600) / 60);
+#elif defined(OS_BSD)
+  if (!g_bProviderTimeZoneSet) {
+    time_t now = time(nullptr);
+    struct tm tm = {};
+
+    localtime_r(&now, &tm);
+
+    g_bProviderTimeZoneSet = true;
+    g_lTimeZoneOffset = tm.tm_gmtoff;
+  }
+  m_tz.tzHour = static_cast<int8_t>(g_lTimeZoneOffset / 3600 * -1);
+  m_tz.tzMinute = static_cast<int8_t>((abs(g_lTimeZoneOffset) % 3600) / 60);
 #else
   if (!g_bProviderTimeZoneSet) {
     g_bProviderTimeZoneSet = true;
