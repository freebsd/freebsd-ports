--- ui/base/dragdrop/os_exchange_data_provider_non_backed.cc.orig	2026-02-11 09:05:39 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_non_backed.cc
@@ -104,7 +104,7 @@ void OSExchangeDataProviderNonBacked::SetPickledData(
 
 std::optional<std::u16string> OSExchangeDataProviderNonBacked::GetString()
     const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (HasFile()) {
     // Various Linux file managers both pass a list of file:// URIs and set the
     // string representation to the URI. We explicitly don't want to return use
