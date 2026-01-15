--- components/services/font_data/font_data_service_impl.cc.orig	2026-01-14 08:33:23 UTC
+++ components/services/font_data/font_data_service_impl.cc
@@ -119,7 +119,7 @@ std::tuple<base::File, uint64_t> FontDataServiceImpl::
   typeface.getResourceName(&font_path);
   base::UmaHistogramBoolean("Chrome.FontDataService.EmptyPathOnGetFileHandle",
                             font_path.isEmpty());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/463411679): `getResourceName()` is not implemented for
   // Linux, so the returned file will always be invalid and a memory region will
   // be shared instead.
