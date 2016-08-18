--- services/shell/public/cpp/lib/initialize_base_and_icu.cc.orig	2016-08-05 14:07:55.178818000 -0400
+++ services/shell/public/cpp/lib/initialize_base_and_icu.cc	2016-08-05 14:08:22.862094000 -0400
@@ -35,6 +35,7 @@
   base::SysInfo::MaxSharedMemorySize();
 #endif
 
+#if !defined(__FreeBSD__)
 #if ICU_UTIL_DATA_IMPL == ICU_UTIL_DATA_FILE
   // Initialize core ICU. We must perform the full initialization before we
   // initialize icu::TimeZone subsystem because otherwise ICU gets in a state
@@ -42,6 +43,7 @@
   // cause crashes.
   CHECK(base::i18n::InitializeICUFromRawMemory(icu_data));
 #endif  // ICU_UTIL_DATA_IMPL == ICU_UTIL_DATA_FILE
+#endif
 
 #if !defined(OS_ANDROID)
   // ICU DateFormat class (used in base/time_format.cc) needs to get the
