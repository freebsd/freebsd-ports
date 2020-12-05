--- net/traffic_annotation/network_traffic_annotation.h.orig	2020-11-13 06:36:46 UTC
+++ net/traffic_annotation/network_traffic_annotation.h
@@ -359,7 +359,7 @@ struct MutablePartialNetworkTrafficAnnotationTag {
 }  // namespace net
 
 // Placeholder for unannotated usages.
-#if !defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 #define TRAFFIC_ANNOTATION_WITHOUT_PROTO(ANNOTATION_ID) \
   net::DefineNetworkTrafficAnnotation(ANNOTATION_ID, "No proto yet.")
 #endif
@@ -370,7 +370,7 @@ struct MutablePartialNetworkTrafficAnnotationTag {
 //
 // On Linux and Windows, use MISSING_TRAFFIC_ANNOTATION or
 // TRAFFIC_ANNOTATION_FOR_TESTS.
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 #define NO_TRAFFIC_ANNOTATION_YET \
   net::DefineNetworkTrafficAnnotation("undefined", "Nothing here yet.")
 
