--- chrome/services/speech/audio_source_fetcher_impl.cc.orig	2023-01-13 08:56:02 UTC
+++ chrome/services/speech/audio_source_fetcher_impl.cc
@@ -121,7 +121,7 @@ void AudioSourceFetcherImpl::Start(
 
   // TODO(crbug.com/1185978): Check implementation / sandbox policy on Mac and
   // Windows.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   is_started_ = true;
   // Initialize the AudioCapturerSource with |this| as the CaptureCallback,
   // get the parameters for the device ID, then start audio capture.
