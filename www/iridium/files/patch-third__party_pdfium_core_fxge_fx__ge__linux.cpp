--- third_party/pdfium/core/fxge/fx_ge_linux.cpp.orig	2019-03-11 22:08:02 UTC
+++ third_party/pdfium/core/fxge/fx_ge_linux.cpp
@@ -146,9 +146,8 @@ std::unique_ptr<SystemFontInfoIface> SystemFontInfoIfa
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
