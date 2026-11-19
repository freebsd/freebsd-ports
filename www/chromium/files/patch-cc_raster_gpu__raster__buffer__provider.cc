--- cc/raster/gpu_raster_buffer_provider.cc.orig	2026-11-19 12:25:27 UTC
+++ cc/raster/gpu_raster_buffer_provider.cc
@@ -106,7 +106,7 @@ GpuRasterBufferProvider::GpuRasterBufferProvider(
       pending_raster_queries_(pending_raster_queries),
       raster_metric_probability_(raster_metric_probability),
       is_using_dmsaa_(
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
           true
 #else
           false
