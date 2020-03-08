--- services/tracing/public/cpp/perfetto/trace_event_data_source.cc.orig	2020-03-03 18:53:56 UTC
+++ services/tracing/public/cpp/perfetto/trace_event_data_source.cc
@@ -101,7 +101,7 @@ void WriteMetadataProto(ChromeMetadataPacket* metadata
 #endif  // defined(OS_ANDROID) && defined(OFFICIAL_BUILD)
 }
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Linux, Android, and Fuchsia all use CLOCK_MONOTONIC. See crbug.com/166153
 // about efforts to unify base::TimeTicks across all platforms.
 constexpr perfetto::protos::pbzero::ClockSnapshot::Clock::BuiltinClocks
