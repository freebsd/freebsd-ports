--- xbmc/peripherals/devices/PeripheralCecAdapter.cpp.orig	2015-05-11 09:54:22 UTC
+++ xbmc/peripherals/devices/PeripheralCecAdapter.cpp
@@ -44,7 +44,7 @@ using namespace ANNOUNCEMENT;
 using namespace CEC;
 using namespace std;
 
-#define CEC_LIB_SUPPORTED_VERSION 0x2100
+#define CEC_LIB_SUPPORTED_VERSION LIBCEC_VERSION_TO_UINT(3, 0, 0)
 
 /* time in seconds to ignore standby commands from devices after the screensaver has been activated */
 #define SCREENSAVER_TIMEOUT       10
@@ -282,7 +282,7 @@ bool CPeripheralCecAdapter::InitialiseFe
     }
     else
     {
-      CLog::Log(LOGDEBUG, "%s - using libCEC v%s", __FUNCTION__, m_cecAdapter->ToString((cec_server_version)m_configuration.serverVersion));
+      CLog::Log(LOGDEBUG, "%s - using libCEC v%s", __FUNCTION__, m_cecAdapter->VersionToString(m_configuration.serverVersion).c_str());
       SetVersionInfo(m_configuration);
     }
 
@@ -295,7 +295,7 @@ bool CPeripheralCecAdapter::InitialiseFe
 
 void CPeripheralCecAdapter::SetVersionInfo(const libcec_configuration &configuration)
 {
-  m_strVersionInfo.Format("libCEC %s - firmware v%d", m_cecAdapter->ToString((cec_server_version)configuration.serverVersion), configuration.iFirmwareVersion);
+  m_strVersionInfo.Format("libCEC %s - firmware v%d", m_cecAdapter->VersionToString(configuration.serverVersion).c_str(), configuration.iFirmwareVersion);
 
   // append firmware build date
   if (configuration.iFirmwareBuildDate != CEC_FW_BUILD_UNKNOWN)
@@ -1303,7 +1303,7 @@ void CPeripheralCecAdapter::SetConfigura
 void CPeripheralCecAdapter::SetConfigurationFromSettings(void)
 {
   // client version matches the version of libCEC that we originally used the API from
-  m_configuration.clientVersion = CEC_CLIENT_VERSION_2_2_0;
+  m_configuration.clientVersion = LIBCEC_VERSION_TO_UINT(3, 0, 0);
 
   // device name 'XBMC'
   snprintf(m_configuration.strDeviceName, 13, "%s", GetSettingString("device_name").c_str());
