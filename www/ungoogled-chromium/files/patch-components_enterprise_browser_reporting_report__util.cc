--- components/enterprise/browser/reporting/report_util.cc.orig	2025-09-22 06:25:21 UTC
+++ components/enterprise/browser/reporting/report_util.cc
@@ -79,6 +79,25 @@ em::SettingValue TranslateSettingValue(
   }
 }
 
+em::ProfileSignalsReport::PasswordProtectionTrigger
+TranslatePasswordProtectionTrigger(
+    std::optional<safe_browsing::PasswordProtectionTrigger> trigger) {
+  if (trigger == std::nullopt) {
+    return em::ProfileSignalsReport::POLICY_UNSET;
+  }
+  switch (trigger.value()) {
+    case safe_browsing::PasswordProtectionTrigger::PASSWORD_PROTECTION_OFF:
+      return em::ProfileSignalsReport::PASSWORD_PROTECTION_OFF;
+    case safe_browsing::PasswordProtectionTrigger::PASSWORD_REUSE:
+      return em::ProfileSignalsReport::PASSWORD_REUSE;
+    case safe_browsing::PasswordProtectionTrigger::PHISHING_REUSE:
+      return em::ProfileSignalsReport::PHISHING_REUSE;
+    case safe_browsing::PasswordProtectionTrigger::
+        PASSWORD_PROTECTION_TRIGGER_MAX:
+      NOTREACHED();
+  }
+}
+
 em::ProfileSignalsReport::RealtimeUrlCheckMode TranslateRealtimeUrlCheckMode(
     enterprise_connectors::EnterpriseRealTimeUrlCheckMode mode) {
   switch (mode) {
@@ -91,6 +110,18 @@ em::ProfileSignalsReport::RealtimeUrlCheckMode Transla
   }
 }
 
+em::ProfileSignalsReport::SafeBrowsingLevel TranslateSafeBrowsingLevel(
+    safe_browsing::SafeBrowsingState level) {
+  switch (level) {
+    case safe_browsing::SafeBrowsingState::NO_SAFE_BROWSING:
+      return em::ProfileSignalsReport::NO_SAFE_BROWSING;
+    case safe_browsing::SafeBrowsingState::STANDARD_PROTECTION:
+      return em::ProfileSignalsReport::STANDARD_PROTECTION;
+    case safe_browsing::SafeBrowsingState::ENHANCED_PROTECTION:
+      return em::ProfileSignalsReport::ENHANCED_PROTECTION;
+  }
+}
+
 #if BUILDFLAG(IS_WIN)
 std::unique_ptr<em::AntiVirusProduct> TranslateAvProduct(
     device_signals::AvProduct av_product) {
@@ -166,7 +197,7 @@ std::string GetSecuritySignalsInReport(
     signals_dict.Set("antivirus_info", std::move(anti_virus_list));
 
     signals_dict.Set("hotfixes", RepeatedFieldptrToList(os_report.hotfixes()));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (os_report.has_distribution_version()) {
       signals_dict.Set("distribution_version",
                        os_report.distribution_version());
