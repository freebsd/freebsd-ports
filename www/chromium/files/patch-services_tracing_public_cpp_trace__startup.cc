--- services/tracing/public/cpp/trace_startup.cc.orig	2025-07-02 06:08:04 UTC
+++ services/tracing/public/cpp/trace_startup.cc
@@ -66,7 +66,7 @@ void EnableStartupTracingIfNeeded(bool with_thread) {
   // Create the PerfettoTracedProcess.
   if (with_thread) {
     g_tracing_with_thread = true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     PerfettoTracedProcess::MaybeCreateInstanceWithThread(
         /*will_trace_thread_restart=*/true);
 #else
