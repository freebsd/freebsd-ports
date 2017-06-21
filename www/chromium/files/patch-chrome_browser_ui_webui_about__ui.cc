--- chrome/browser/ui/webui/about_ui.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/webui/about_ui.cc
@@ -420,7 +420,7 @@ std::string ChromeURLs() {
   return html;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kAboutDiscardsRunCommand[] = "run";
 
@@ -539,7 +539,7 @@ std::string AboutDiscards(const std::string& path) {
   output.append(base::StringPrintf("<a href='%s%s'>Discard tab now</a>",
                                    chrome::kChromeUIDiscardsURL,
                                    kAboutDiscardsRunCommand));
-
+#if !defined(OS_BSD)
   base::SystemMemoryInfoKB meminfo;
   base::GetSystemMemoryInfo(&meminfo);
   output.append("<h3>System memory information in MB</h3>");
@@ -551,6 +551,7 @@ std::string AboutDiscards(const std::string& path) {
       "Free",
       base::IntToString(base::SysInfo::AmountOfAvailablePhysicalMemory() /
                         1024 / 1024)));
+#endif
 #if defined(OS_CHROMEOS)
   int mem_allocated_kb = meminfo.active_anon + meminfo.inactive_anon;
 #if defined(ARCH_CPU_ARM_FAMILY)
@@ -580,7 +581,7 @@ std::string AboutDiscards(const std::string& path) {
   return output;
 }
 
-#endif  // OS_WIN || OS_MACOSX || OS_LINUX
+#endif  // OS_WIN || OS_MACOSX || OS_LINUX || defined(OS_BSD)
 
 // AboutDnsHandler bounces the request back to the IO thread to collect
 // the DNS information.
@@ -642,7 +643,7 @@ class AboutDnsHandler : public base::RefCountedThreadS
   DISALLOW_COPY_AND_ASSIGN(AboutDnsHandler);
 };
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -717,14 +718,14 @@ void AboutUIHTMLSource::StartDataRequest(
     } else {
       response = raw_response.as_string();
     }
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUIDiscardsHost) {
     response = AboutDiscards(path);
 #endif
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
