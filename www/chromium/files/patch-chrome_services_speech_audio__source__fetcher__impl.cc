--- chrome/services/speech/audio_source_fetcher_impl.cc.orig	2021-09-24 04:26:00 UTC
+++ chrome/services/speech/audio_source_fetcher_impl.cc
@@ -68,7 +68,7 @@ void AudioSourceFetcherImpl::Start(
 
   // TODO(crbug.com/1185978): Check implementation / sandbox policy on Mac and
   // Windows.
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
   is_started_ = true;
   // Initialize the AudioCapturerSource with |this| as the CaptureCallback,
   // get the parameters for the device ID, then start audio capture.
