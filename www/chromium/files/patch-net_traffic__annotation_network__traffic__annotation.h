--- net/traffic_annotation/network_traffic_annotation.h.orig	2022-02-28 16:54:41 UTC
+++ net/traffic_annotation/network_traffic_annotation.h
@@ -371,7 +371,7 @@ struct MutablePartialNetworkTrafficAnnotationTag {
 }  // namespace net
 
 // Placeholder for unannotated usages.
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 #define TRAFFIC_ANNOTATION_WITHOUT_PROTO(ANNOTATION_ID) \
   net::DefineNetworkTrafficAnnotation(ANNOTATION_ID, "No proto yet.")
 #endif
@@ -385,7 +385,7 @@ struct MutablePartialNetworkTrafficAnnotationTag {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 
 #define NO_TRAFFIC_ANNOTATION_YET \
   net::DefineNetworkTrafficAnnotation("undefined", "Nothing here yet.")
