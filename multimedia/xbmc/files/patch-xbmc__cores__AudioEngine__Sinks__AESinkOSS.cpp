diff --git xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp
index f6ec980..7bcb6d6 100644
--- xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp
+++ xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp
@@ -298,6 +298,8 @@ bool CAESinkOSS::Initialize(AEAudioFormat &format, std::string &device)
 #endif
 
   int tmp = (CAEUtil::DataFormatToBits(format.m_dataFormat) >> 3) * format.m_channelLayout.Count() * OSS_FRAMES;
+  if (AE_IS_RAW_HD(format.m_dataFormat))
+    tmp *= 8;
   int pos = 0;
   while ((tmp & 0x1) == 0x0)
   {
@@ -478,12 +480,23 @@ void CAESinkOSS::EnumerateDevicesEx(AEDeviceInfoList &list, bool force)
     devicename << cardinfo.shortname << " " << cardinfo.longname;
     info.m_displayName = devicename.str();
 
-    if (info.m_displayName.find("HDMI") != std::string::npos)
+    info.m_dataFormats.push_back(AE_FMT_S16NE);
+    info.m_dataFormats.push_back(AE_FMT_S32NE);
+    if (info.m_displayName.find("HDMI") != std::string::npos) {
       info.m_deviceType = AE_DEVTYPE_HDMI;
-    else if (info.m_displayName.find("Digital") != std::string::npos)
+      info.m_dataFormats.push_back(AE_FMT_AC3);
+      info.m_dataFormats.push_back(AE_FMT_DTS);
+      info.m_dataFormats.push_back(AE_FMT_EAC3);
+      info.m_dataFormats.push_back(AE_FMT_TRUEHD);
+      info.m_dataFormats.push_back(AE_FMT_DTSHD);
+      info.m_dataFormats.push_back(AE_FMT_LPCM);
+    } else if (info.m_displayName.find("Digital") != std::string::npos) {
       info.m_deviceType = AE_DEVTYPE_IEC958;
-    else
+      info.m_dataFormats.push_back(AE_FMT_AC3);
+      info.m_dataFormats.push_back(AE_FMT_DTS);
+    } else {
       info.m_deviceType = AE_DEVTYPE_PCM;
+    }
  
     oss_audioinfo ainfo;
     memset(&ainfo, 0, sizeof(ainfo));
