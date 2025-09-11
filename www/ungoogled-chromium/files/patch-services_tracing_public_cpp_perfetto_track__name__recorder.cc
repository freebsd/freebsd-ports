--- services/tracing/public/cpp/perfetto/track_name_recorder.cc.orig	2025-09-10 13:22:16 UTC
+++ services/tracing/public/cpp/perfetto/track_name_recorder.cc
@@ -51,7 +51,7 @@ void FillThreadTrack(const perfetto::ThreadTrack& trac
   if (thread_type != ChromeThreadDescriptor::THREAD_UNSPECIFIED) {
     desc.mutable_chrome_thread()->set_thread_type(thread_type);
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   if (base::GetCurrentProcId() !=
       base::trace_event::TraceLog::GetInstance()->process_id()) {
     desc.mutable_chrome_thread()->set_is_sandboxed_tid(true);
