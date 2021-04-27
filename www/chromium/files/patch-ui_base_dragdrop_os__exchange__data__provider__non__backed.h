--- ui/base/dragdrop/os_exchange_data_provider_non_backed.h.orig	2021-04-14 18:41:37 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_non_backed.h
@@ -61,7 +61,7 @@ class COMPONENT_EXPORT(UI_BASE) OSExchangeDataProvider
   bool HasURL(FilenameToURLPolicy policy) const override;
   bool HasFile() const override;
   bool HasCustomFormat(const ClipboardFormatType& format) const override;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   void SetFileContents(const base::FilePath& filename,
                        const std::string& file_contents) override;
 #endif
