--- ./xbmc/utils/SystemInfo.h.orig	2010-06-01 17:19:39.000000000 +0200
+++ ./xbmc/utils/SystemInfo.h	2010-12-01 12:17:34.284098904 +0100
@@ -87,7 +87,7 @@
   bool GetHDDInfo(CStdString& strHDDModel, CStdString& strHDDSerial,CStdString& strHDDFirmware,CStdString& strHDDpw,CStdString& strHDDLockState);
   bool GetRefurbInfo(CStdString& rfi_FirstBootTime, CStdString& rfi_PowerCycleCount);
 
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
   CStdString GetLinuxDistro();
 #endif
 #ifdef _LINUX
