--- backend/flipperzero/helper/deviceinfohelper.cpp.orig	2023-03-27 09:51:38 UTC
+++ backend/flipperzero/helper/deviceinfohelper.cpp
@@ -103,7 +103,8 @@ void VCPDeviceInfoHelper::findSerialPort()
 
 void VCPDeviceInfoHelper::findSerialPort()
 {
-    auto *finder = new SerialFinder(m_deviceInfo.usbInfo.serialNumber(), this);
+    QString serialBsd = QString(m_deviceInfo.usbInfo.serialNumber()).remove(QString("_"));
+    auto *finder = new SerialFinder(serialBsd, this);
 
     connect(finder, &SerialFinder::finished, this, [=](const QSerialPortInfo &portInfo) {
         if(portInfo.isNull()) {
