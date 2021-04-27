--- ui/base/dragdrop/os_exchange_data_provider_non_backed.cc.orig	2021-04-14 18:41:37 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_non_backed.cc
@@ -100,14 +100,14 @@ void OSExchangeDataProviderNonBacked::SetPickledData(
 }
 
 bool OSExchangeDataProviderNonBacked::GetString(base::string16* data) const {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (HasFile()) {
     // Various Linux file managers both pass a list of file:// URIs and set the
     // string representation to the URI. We explicitly don't want to return use
     // this representation.
     return false;
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   if ((formats_ & OSExchangeData::STRING) == 0)
     return false;
@@ -184,7 +184,7 @@ bool OSExchangeDataProviderNonBacked::HasCustomFormat(
   return base::Contains(pickle_data_, format);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void OSExchangeDataProviderNonBacked::SetFileContents(
     const base::FilePath& filename,
     const std::string& file_contents) {
