--- ui/ozone/platform/wayland/host/wayland_exchange_data_provider.cc.orig	2026-05-09 18:09:27 UTC
+++ ui/ozone/platform/wayland/host/wayland_exchange_data_provider.cc
@@ -74,7 +74,7 @@ int MimeTypeToFormat(const std::string& mime_type) {
   if (mime_type == ui::kMimeTypeDataTransferCustomData) {
     return OSExchangeData::PICKLED_DATA;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mime_type == ui::kMimeTypePortalFileTransfer ||
       mime_type == ui::kMimeTypePortalFiles) {
     return OSExchangeData::PICKLED_DATA;
@@ -210,7 +210,7 @@ std::unique_ptr<OSExchangeDataProvider> WaylandExchang
     const {
   auto clone = std::make_unique<WaylandExchangeDataProvider>();
   CopyData(clone.get());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   clone->additional_data_ = additional_data_;
 #endif
   return clone;
@@ -254,7 +254,7 @@ std::vector<std::string> WaylandExchangeDataProvider::
     mime_types.push_back(mime_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   for (const auto& item : additional_data_) {
     mime_types.push_back(item.first);
   }
@@ -272,7 +272,7 @@ void WaylandExchangeDataProvider::AddData(PlatformClip
   DCHECK(data);
   DCHECK(IsMimeTypeSupported(mime_type));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mime_type == ui::kMimeTypePortalFileTransfer ||
       mime_type == ui::kMimeTypePortalFiles) {
     additional_data_[mime_type] = base::as_string_view(*data);
@@ -345,7 +345,7 @@ bool WaylandExchangeDataProvider::ExtractData(const st
     *out_content = std::string(pickle->AsStringView());
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto it = additional_data_.find(mime_type);
   if (it != additional_data_.end()) {
     *out_content = it->second;
