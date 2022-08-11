--- services/tracing/public/cpp/perfetto/perfetto_config.cc.orig	2022-06-17 14:20:10 UTC
+++ services/tracing/public/cpp/perfetto/perfetto_config.cc
@@ -125,7 +125,7 @@ void AddDataSourceConfigs(
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_CHROMEOS_ASH) || \
-    (BUILDFLAG(IS_CHROMECAST) && BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_CHROMECAST) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)))
     if (source_names.empty() ||
         source_names.count(tracing::mojom::kSystemTraceDataSourceName) == 1) {
       AddDataSourceConfig(
