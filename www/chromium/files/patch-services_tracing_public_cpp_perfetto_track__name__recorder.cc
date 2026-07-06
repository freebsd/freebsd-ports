--- services/tracing/public/cpp/perfetto/track_name_recorder.cc.orig	2026-07-01 06:24:19 UTC
+++ services/tracing/public/cpp/perfetto/track_name_recorder.cc
@@ -53,7 +53,7 @@ void FillThreadTrack(const perfetto::ThreadTrack& trac
     desc.mutable_chrome_thread()->set_thread_type(
         static_cast<int32_t>(thread_type));
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   if (base::GetCurrentProcId() != perfetto::Platform::GetCurrentProcessId()) {
     desc.mutable_chrome_thread()->set_is_sandboxed_tid(true);
   }
