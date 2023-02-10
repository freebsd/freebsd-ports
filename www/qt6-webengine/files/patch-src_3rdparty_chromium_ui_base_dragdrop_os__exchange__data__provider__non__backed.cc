--- src/3rdparty/chromium/ui/base/dragdrop/os_exchange_data_provider_non_backed.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/base/dragdrop/os_exchange_data_provider_non_backed.cc
@@ -94,7 +94,7 @@ bool OSExchangeDataProviderNonBacked::GetString(std::u
 }
 
 bool OSExchangeDataProviderNonBacked::GetString(std::u16string* data) const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (HasFile()) {
     // Various Linux file managers both pass a list of file:// URIs and set the
     // string representation to the URI. We explicitly don't want to return use
