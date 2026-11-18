--- chrome/browser/speech/chrome_speech_recognition_service.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/speech/chrome_speech_recognition_service.cc
@@ -255,7 +255,7 @@ void ChromeSpeechRecognitionService::LaunchIfNotRunnin
 
   content::ServiceProcessHost::Options options;
   options.WithDisplayName(IDS_UTILITY_PROCESS_SPEECH_RECOGNITION_SERVICE_NAME);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // libsoda.so has to be dlopen()ed before the sandbox is engaged, so tell the
   // utility process which binary it is going to be asked to load below.
   options.WithExtraCommandLineSwitchKeyValues(
