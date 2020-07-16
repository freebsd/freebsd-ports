--- xbmc/windowing/rpi/WinSystemRpi.cpp.orig	2020-05-19 20:47:38 UTC
+++ xbmc/windowing/rpi/WinSystemRpi.cpp
@@ -49,13 +49,21 @@ CWinSystemRpi::CWinSystemRpi() :
   if (getenv("KODI_AE_SINK"))
     envSink = getenv("KODI_AE_SINK");
 
-  if (StringUtils::EqualsNoCase(envSink, "PULSE"))
+  if (StringUtils::EqualsNoCase(envSink, "ALSA"))
   {
+    OPTIONALS::ALSARegister();
+  }
+  else if (StringUtils::EqualsNoCase(envSink, "PULSE"))
+  {
     OPTIONALS::PulseAudioRegister();
   }
+  else if (StringUtils::EqualsNoCase(envSink, "SNDIO"))
+  {
+    OPTIONALS::SndioRegister();
+  }
   else
   {
-    OPTIONALS::ALSARegister();
+    OPTIONALS::OSSRegister();
   }
 
   CLinuxPowerSyscall::Register();
