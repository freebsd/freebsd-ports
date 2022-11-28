--- dfu/device/stm32wb55/infotable.h.orig	2022-11-27 21:57:44 UTC
+++ dfu/device/stm32wb55/infotable.h
@@ -52,6 +52,7 @@ struct FUSDeviceInfoTable
     uint32_t  reserved2;
     uint64_t  UID64;
     uint16_t  deviceID;
+    uint32_t  padding_ /* padding for 32 bit build */;
 };
 
 struct DeviceInfoTable {
