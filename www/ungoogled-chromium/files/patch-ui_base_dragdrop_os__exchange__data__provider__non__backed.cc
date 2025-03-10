--- ui/base/dragdrop/os_exchange_data_provider_non_backed.cc.orig	2025-01-25 09:34:31 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_non_backed.cc
@@ -98,7 +98,7 @@ void OSExchangeDataProviderNonBacked::SetPickledData(
 
 std::optional<std::u16string> OSExchangeDataProviderNonBacked::GetString()
     const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (HasFile()) {
     // Various Linux file managers both pass a list of file:// URIs and set the
     // string representation to the URI. We explicitly don't want to return use
