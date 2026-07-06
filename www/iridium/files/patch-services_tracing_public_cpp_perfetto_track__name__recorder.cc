--- services/tracing/public/cpp/perfetto/track_name_recorder.cc.orig	2026-06-10 12:51:34 UTC
+++ services/tracing/public/cpp/perfetto/track_name_recorder.cc
@@ -54,7 +54,7 @@ void FillThreadTrack(const perfetto::ThreadTrack& trac
     desc.mutable_chrome_thread()->set_thread_type(
         static_cast<int32_t>(thread_type));
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   if (base::GetCurrentProcId() !=
       base::trace_event::TraceLog::GetInstance()->process_id()) {
     desc.mutable_chrome_thread()->set_is_sandboxed_tid(true);
