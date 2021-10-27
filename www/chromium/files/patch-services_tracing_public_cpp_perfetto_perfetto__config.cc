--- services/tracing/public/cpp/perfetto/perfetto_config.cc.orig	2021-09-24 04:26:09 UTC
+++ services/tracing/public/cpp/perfetto/perfetto_config.cc
@@ -120,7 +120,7 @@ void AddDataSourceConfigs(
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_CHROMEOS_ASH) || \
-    (BUILDFLAG(IS_CHROMECAST) && defined(OS_LINUX))
+    (BUILDFLAG(IS_CHROMECAST) && (defined(OS_LINUX) || defined(OS_BSD)))
     if (source_names.empty() ||
         source_names.count(tracing::mojom::kSystemTraceDataSourceName) == 1) {
       AddDataSourceConfig(
