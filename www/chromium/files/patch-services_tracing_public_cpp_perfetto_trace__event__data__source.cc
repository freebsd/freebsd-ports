--- services/tracing/public/cpp/perfetto/trace_event_data_source.cc.orig	2019-12-17 19:52:52 UTC
+++ services/tracing/public/cpp/perfetto/trace_event_data_source.cc
@@ -102,7 +102,7 @@ void WriteMetadataProto(ChromeMetadataPacket* metadata
 #endif  // defined(OS_ANDROID) && defined(OFFICIAL_BUILD)
 }
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Linux, Android, and Fuchsia all use CLOCK_MONOTONIC. See crbug.com/166153
 // about efforts to unify base::TimeTicks across all platforms.
 constexpr perfetto::protos::pbzero::ClockSnapshot::Clock::BuiltinClocks
