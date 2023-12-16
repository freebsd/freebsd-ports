--- src/3rdparty/chromium/printing/backend/cups_helper.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/printing/backend/cups_helper.cc
@@ -127,7 +127,7 @@ void GetResolutionSettings(ppd_file_t* ppd,
   // found.
 #if BUILDFLAG(IS_MAC)
   constexpr gfx::Size kDefaultMissingDpi(kDefaultMacDpi, kDefaultMacDpi);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   constexpr gfx::Size kDefaultMissingDpi(kPixelsPerInch, kPixelsPerInch);
 #else
   constexpr gfx::Size kDefaultMissingDpi(kDefaultPdfDpi, kDefaultPdfDpi);
