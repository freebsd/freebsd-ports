--- ui/base/dragdrop/os_exchange_data_provider_non_backed.cc.orig	2022-02-07 13:39:41 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_non_backed.cc
@@ -85,7 +85,7 @@ void OSExchangeDataProviderNonBacked::SetPickledData(
 }
 
 bool OSExchangeDataProviderNonBacked::GetString(std::u16string* data) const {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (HasFile()) {
     // Various Linux file managers both pass a list of file:// URIs and set the
     // string representation to the URI. We explicitly don't want to return use
