--- remoting/protocol/webrtc_video_stream.cc.orig	2026-06-05 13:45:06 UTC
+++ remoting/protocol/webrtc_video_stream.cc
@@ -255,7 +255,7 @@ WebrtcVideoStream::WebrtcVideoStream(const SessionOpti
     : session_options_(session_options) {
 // TODO: yuweih - Check if the other platforms can also be updated to run on a
 // dedicated thread.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   core_task_runner_ = base::ThreadPool::CreateSingleThreadTaskRunner(
       {base::TaskPriority::HIGHEST},
       base::SingleThreadTaskRunnerThreadMode::DEDICATED);
