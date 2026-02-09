--- printing/mojom/printing_context_mojom_traits_unittest.cc.orig	2026-02-11 09:05:39 UTC
+++ printing/mojom/printing_context_mojom_traits_unittest.cc
@@ -81,7 +81,7 @@ base::Value::Dict GenerateSampleSystemPrintDialogData(
              "file:///foo/bar.pdf");
   }
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   data.Set(kLinuxSystemPrintDialogDataPrinter, "printer-name");
   data.Set(kLinuxSystemPrintDialogDataPrintSettings, "print-settings-foo");
   data.Set(kLinuxSystemPrintDialogDataPageSetup, "page-setup-bar");
@@ -93,7 +93,7 @@ base::Value::Dict GenerateSampleSystemPrintDialogData(
   return data;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 base::Value::Dict GenerateSampleSystemPrintDialogDataPortal() {
   base::Value::Dict data;
   data.Set(kLinuxSystemPrintDialogDataPrintSettingsBin,
@@ -132,7 +132,7 @@ const PageMargins kPrintSettingsCustomMarginsInMicrons
                                                        /*top=*/10583,
                                                        /*bottom=*/12347);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 PrintSettings::AdvancedSettings GenerateSampleAdvancedSettings() {
   PrintSettings::AdvancedSettings advanced_settings;
   advanced_settings.emplace("advanced-setting-A", base::Value("setting-A"));
@@ -225,7 +225,7 @@ PrintSettings GenerateSamplePrintSettingsCommon() {
   settings.set_device_name(kPrintSettingsDeviceName);
   settings.set_requested_media(kPrintSettingsRequestedMedia);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   PrintSettings::AdvancedSettings& advanced_settings =
       settings.advanced_settings();
   for (const auto& item : kPrintSettingsAdvancedSettings)
@@ -563,7 +563,7 @@ TEST(PrintingContextMojomTraitsTest,
 
   EXPECT_EQ(output.pages_per_sheet(), kPrintSettingsPagesPerSheet1);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(output.advanced_settings(), kPrintSettingsAdvancedSettings);
 #endif
 
@@ -616,7 +616,7 @@ TEST(PrintingContextMojomTraitsTest,
                                kPrintSettingsCustomMarginsInMicrons));
   EXPECT_EQ(output.pages_per_sheet(), kPrintSettingsPagesPerSheet2);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(output.advanced_settings(), kPrintSettingsAdvancedSettings);
 #endif
 
@@ -689,7 +689,7 @@ TEST(PrintingContextMojomTraitsTest,
   EXPECT_EQ(output.page_setup_device_units(), kInput.page_setup_device_units());
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 TEST(PrintingContextMojomTraitsTest,
      TestSerializeAndDeserializePrintSettingsEmptyAdvancedSettings) {
   PrintSettings input = GenerateSamplePrintSettingsDefaultMargins();
@@ -887,7 +887,7 @@ TEST(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST(PrintingContextMojomTraitsTest,
      TestSerializeAndDeserializePrintSettingsSystemPrintDialogDataPortal) {
   PrintSettings input = GenerateSamplePrintSettingsDefaultMargins();
