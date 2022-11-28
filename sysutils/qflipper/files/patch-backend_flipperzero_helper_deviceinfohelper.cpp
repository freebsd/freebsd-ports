--- backend/flipperzero/helper/deviceinfohelper.cpp.orig	2022-11-28 05:07:31 UTC
+++ backend/flipperzero/helper/deviceinfohelper.cpp
@@ -97,7 +97,8 @@ void VCPDeviceInfoHelper::findSerialPort()
 
 void VCPDeviceInfoHelper::findSerialPort()
 {
-    auto *finder = new SerialFinder(m_deviceInfo.usbInfo.serialNumber(), this);
+    QString serialBsd = QString(m_deviceInfo.usbInfo.serialNumber()).remove(QString("_"));
+    auto *finder = new SerialFinder(serialBsd, this);
 
     connect(finder, &SerialFinder::finished, this, [=](const QSerialPortInfo &portInfo) {
         if(portInfo.isNull()) {
