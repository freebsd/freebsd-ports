--- printing/mojom/printing_context_mojom_traits_unittest.cc.orig	2025-09-10 13:22:16 UTC
+++ printing/mojom/printing_context_mojom_traits_unittest.cc
@@ -80,7 +80,7 @@ base::Value::Dict GenerateSampleSystemPrintDialogData(
     data.Set(kMacSystemPrintDialogDataDestinationLocation, "/foo/bar.pdf");
   }
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   data.Set(kLinuxSystemPrintDialogDataPrinter, "printer-name");
   data.Set(kLinuxSystemPrintDialogDataPrintSettings, "print-settings-foo");
   data.Set(kLinuxSystemPrintDialogDataPageSetup, "page-setup-bar");
@@ -117,7 +117,7 @@ const PageMargins kPrintSettingsCustomMarginsInMicrons
                                                        /*top=*/10583,
                                                        /*bottom=*/12347);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 PrintSettings::AdvancedSettings GenerateSampleAdvancedSettings() {
   PrintSettings::AdvancedSettings advanced_settings;
   advanced_settings.emplace("advanced-setting-A", base::Value("setting-A"));
@@ -210,7 +210,7 @@ PrintSettings GenerateSamplePrintSettingsCommon() {
   settings.set_device_name(kPrintSettingsDeviceName);
   settings.set_requested_media(kPrintSettingsRequestedMedia);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   PrintSettings::AdvancedSettings& advanced_settings =
       settings.advanced_settings();
   for (const auto& item : kPrintSettingsAdvancedSettings)
@@ -548,7 +548,7 @@ TEST(PrintingContextMojomTraitsTest,
 
   EXPECT_EQ(output.pages_per_sheet(), kPrintSettingsPagesPerSheet1);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(output.advanced_settings(), kPrintSettingsAdvancedSettings);
 #endif
 
@@ -601,7 +601,7 @@ TEST(PrintingContextMojomTraitsTest,
                                kPrintSettingsCustomMarginsInMicrons));
   EXPECT_EQ(output.pages_per_sheet(), kPrintSettingsPagesPerSheet2);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(output.advanced_settings(), kPrintSettingsAdvancedSettings);
 #endif
 
@@ -674,7 +674,7 @@ TEST(PrintingContextMojomTraitsTest,
   EXPECT_EQ(output.page_setup_device_units(), kInput.page_setup_device_units());
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 TEST(PrintingContextMojomTraitsTest,
      TestSerializeAndDeserializePrintSettingsEmptyAdvancedSettings) {
   PrintSettings input = GenerateSamplePrintSettingsDefaultMargins();
@@ -872,7 +872,7 @@ TEST(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST(
     PrintingContextMojomTraitsTest,
     TestSerializeAndDeserializePrintSettingsSystemPrintDialogPrinterInvalidDataType) {
