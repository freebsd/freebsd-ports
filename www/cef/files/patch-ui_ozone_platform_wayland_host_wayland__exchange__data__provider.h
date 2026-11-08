--- ui/ozone/platform/wayland/host/wayland_exchange_data_provider.h.orig	2026-03-15 17:43:38 UTC
+++ ui/ozone/platform/wayland/host/wayland_exchange_data_provider.h
@@ -41,7 +41,7 @@ class WaylandExchangeDataProvider final
   void AddData(PlatformClipboard::Data data, const std::string& mime_type);
 
  private:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::map<std::string, std::string> additional_data_;
 #endif
 };
