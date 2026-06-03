--- components/enterprise/browser/reporting/report_util.cc.orig	2026-04-15 11:25:12 UTC
+++ components/enterprise/browser/reporting/report_util.cc
@@ -169,7 +169,7 @@ std::string GetSecuritySignalsInReport(
     signals_dict.Set("antivirus_info", std::move(anti_virus_list));
 
     signals_dict.Set("hotfixes", RepeatedFieldptrToList(os_report.hotfixes()));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (os_report.has_distribution_version()) {
       signals_dict.Set("distribution_version",
                        os_report.distribution_version());
