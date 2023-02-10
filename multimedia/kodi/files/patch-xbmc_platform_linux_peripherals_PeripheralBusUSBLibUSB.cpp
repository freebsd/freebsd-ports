--- xbmc/platform/linux/peripherals/PeripheralBusUSBLibUSB.cpp.orig	2022-05-22 14:00:05 UTC
+++ xbmc/platform/linux/peripherals/PeripheralBusUSBLibUSB.cpp
@@ -42,7 +42,7 @@ bool CPeripheralBusUSB::PerformDeviceScan(PeripheralSc
                                  GetType(dev->config[0].interface[0].altsetting[0].bInterfaceClass) :
                                  GetType(dev->descriptor.bDeviceClass);
 #ifdef TARGET_FREEBSD
-      result.m_strLocation = std::to_string(dev->filename);
+      result.m_strLocation = dev->filename;
 #else
       result.m_strLocation = StringUtils::Format("/bus{}/dev{}", bus->dirname, dev->filename);
 #endif
