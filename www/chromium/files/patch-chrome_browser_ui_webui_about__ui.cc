--- chrome/browser/ui/webui/about_ui.cc.orig	2017-06-21 00:03:13.000000000 +0200
+++ chrome/browser/ui/webui/about_ui.cc	2017-06-27 01:22:41.801626000 +0200
@@ -420,7 +420,7 @@
   return html;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kAboutDiscardsRunCommand[] = "run";
 
@@ -539,11 +539,13 @@
   output.append(base::StringPrintf("<a href='%s%s'>Discard tab now</a>",
                                    chrome::kChromeUIDiscardsURL,
                                    kAboutDiscardsRunCommand));
-
+#if !defined(OS_BSD)
   base::SystemMemoryInfoKB meminfo;
   base::GetSystemMemoryInfo(&meminfo);
+#endif
   output.append("<h3>System memory information in MB</h3>");
   output.append("<table>");
+#if !defined(OS_BSD)
   // Start with summary statistics.
   output.append(AddStringRow(
       "Total", base::IntToString(meminfo.total / 1024)));
@@ -575,12 +577,13 @@
   output.append(AddStringRow(
       "Graphics", base::IntToString(meminfo.gem_size / 1024 / 1024)));
 #endif  // OS_CHROMEOS
+#endif
   output.append("</table>");
   AppendFooter(&output);
   return output;
 }
 
-#endif  // OS_WIN || OS_MACOSX || OS_LINUX
+#endif  // OS_WIN || OS_MACOSX || OS_LINUX || defined(OS_BSD)
 
 // AboutDnsHandler bounces the request back to the IO thread to collect
 // the DNS information.
@@ -642,7 +645,7 @@
   DISALLOW_COPY_AND_ASSIGN(AboutDnsHandler);
 };
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -717,14 +720,14 @@
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
