diff --git xbmc/settings/AdvancedSettings.cpp xbmc/settings/AdvancedSettings.cpp
index d14b139..3275967 100644
--- xbmc/settings/AdvancedSettings.cpp
+++ xbmc/settings/AdvancedSettings.cpp
@@ -100,6 +100,7 @@ void CAdvancedSettings::Initialize()
   m_DXVACheckCompatibilityPresent = false;
   m_DXVAForceProcessorRenderer = true;
   m_videoFpsDetect = 1;
+  m_videoDefaultLatency = 0.0;
 
   m_musicUseTimeSeeking = true;
   m_musicTimeSeekForward = 10;
@@ -542,7 +543,6 @@ void CAdvancedSettings::ParseSettingsFile(const CStdString &file)
     XMLUtils::GetInt(pElement, "fpsdetect", m_videoFpsDetect, 0, 2);
 
     // Store global display latency settings
-    m_videoDefaultLatency = 0;
     TiXmlElement* pVideoLatency = pElement->FirstChildElement("latency");
     if (pVideoLatency)
     {
