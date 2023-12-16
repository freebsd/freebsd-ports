--- OvmfPkg/Bhyve/PlatformPei/Platform.c.orig	2023-11-17 12:26:16 UTC
+++ OvmfPkg/Bhyve/PlatformPei/Platform.c
@@ -153,8 +153,8 @@ MemMapInitialization (
   UINT64         PciIoSize;
   RETURN_STATUS  PcdStatus;
 
-  PciIoBase = 0xC000;
-  PciIoSize = 0x4000;
+  PciIoBase = 0x2000;
+  PciIoSize = 0xE000;
 
   //
   // Create Memory Type Information HOB
