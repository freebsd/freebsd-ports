--- remoting/protocol/webrtc_video_stream.cc.orig	2023-12-10 06:10:27 UTC
+++ remoting/protocol/webrtc_video_stream.cc
@@ -263,7 +263,7 @@ WebrtcVideoStream::WebrtcVideoStream(const std::string
     : stream_name_(stream_name), session_options_(session_options) {
 // TODO(joedow): Dig into the threading model on other platforms to see if they
 // can also be updated to run on a dedicated thread.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   core_task_runner_ = base::ThreadPool::CreateSingleThreadTaskRunner(
       {base::TaskPriority::HIGHEST},
       base::SingleThreadTaskRunnerThreadMode::DEDICATED);
