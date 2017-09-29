--- chrome/browser/ui/webui/about_ui.cc.orig	2017-09-05 21:05:14.000000000 +0200
+++ chrome/browser/ui/webui/about_ui.cc	2017-09-06 18:59:58.102599000 +0200
@@ -420,7 +420,7 @@
   return html;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kAboutDiscardsRunCommand[] = "run";
 const char kAboutDiscardsSkipUnloadHandlersCommand[] = "skip_unload_handlers";
@@ -564,10 +564,13 @@
       "<a href='%s%s'>Discard tab now (safely)</a>",
       chrome::kChromeUIDiscardsURL, kAboutDiscardsRunCommand));
 
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
@@ -599,12 +602,13 @@
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
@@ -666,7 +670,7 @@
   DISALLOW_COPY_AND_ASSIGN(AboutDnsHandler);
 };
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -723,14 +727,14 @@
                      .as_string();
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
