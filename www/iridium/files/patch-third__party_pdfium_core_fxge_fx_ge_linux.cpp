--- third_party/pdfium/core/fxge/fx_ge_linux.cpp.orig	2017-09-10 01:29:26.531645000 +0200
+++ third_party/pdfium/core/fxge/fx_ge_linux.cpp	2017-09-10 01:35:18.727698000 +0200
@@ -149,9 +149,8 @@
     const char** pUserPaths) {
   auto pInfo = pdfium::MakeUnique<CFX_LinuxFontInfo>();
   if (!pInfo->ParseFontCfg(pUserPaths)) {
-    pInfo->AddPath("/usr/share/fonts");
-    pInfo->AddPath("/usr/share/X11/fonts/Type1");
-    pInfo->AddPath("/usr/share/X11/fonts/TTF");
+    pInfo->AddPath("/usr/local/share/fonts/Type1");
+    pInfo->AddPath("/usr/local/share/fonts/TTF");
     pInfo->AddPath("/usr/local/share/fonts");
   }
   return std::move(pInfo);
