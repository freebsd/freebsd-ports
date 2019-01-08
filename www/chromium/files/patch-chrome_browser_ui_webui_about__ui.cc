--- chrome/browser/ui/webui/about_ui.cc.orig	2018-11-19 19:55:04.000000000 +0100
+++ chrome/browser/ui/webui/about_ui.cc	2018-12-04 17:47:53.178444000 +0100
@@ -393,7 +393,7 @@
   return html;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -448,7 +448,7 @@
                      .GetRawDataResource(idr)
                      .as_string();
     }
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
