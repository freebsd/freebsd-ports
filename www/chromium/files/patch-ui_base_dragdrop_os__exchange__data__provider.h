--- ui/base/dragdrop/os_exchange_data_provider.h.orig	2021-04-14 18:41:37 UTC
+++ ui/base/dragdrop/os_exchange_data_provider.h
@@ -73,7 +73,7 @@ class COMPONENT_EXPORT(UI_BASE_DATA_EXCHANGE) OSExchan
   virtual bool HasFile() const = 0;
   virtual bool HasCustomFormat(const ClipboardFormatType& format) const = 0;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
   virtual void SetFileContents(const base::FilePath& filename,
                                const std::string& file_contents) = 0;
 #endif
