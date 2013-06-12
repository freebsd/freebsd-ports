--- ./src/lib/adapter/Pulse-Eight/USBCECAdapterDetection.cpp.orig	2013-05-13 15:09:14.000000000 +0200
+++ ./src/lib/adapter/Pulse-Eight/USBCECAdapterDetection.cpp	2013-06-12 16:31:03.000000000 +0200
@@ -61,6 +61,8 @@
 #include <libudev.h>
 }
 #elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #include <stdio.h>
 #include <unistd.h>
 #endif
@@ -434,22 +436,77 @@
   }
 #elif defined(__FreeBSD__)
   char devicePath[PATH_MAX + 1];
+  char infos[512];
+  char sysctlname[32];
+  char ttyname[8];
+  char *pos;
+  size_t infos_size = sizeof(infos);
   int i;
 
-  for (i = 0; i < 8; ++i)
+  for (i = 0; ; ++i)
   {
-    (void)snprintf(devicePath, sizeof(devicePath), "/dev/ttyU%d", i);
-    if (strDevicePath && strcmp(devicePath, strDevicePath) != 0)
+    unsigned int iVendor, iProduct;
+    memset(infos, 0, sizeof(infos));
+    (void)snprintf(sysctlname, sizeof(sysctlname),
+      "dev.umodem.%d.%%pnpinfo", i);
+    if (sysctlbyname(sysctlname, infos, &infos_size,
+      NULL, 0) != 0)
+        break;
+    pos = strstr(infos, "vendor=");
+    if (pos == NULL)
       continue;
-    if (!access(devicePath, 0))
-    {
-      snprintf(deviceList[iFound].strComPath, sizeof(deviceList[iFound].strComPath), "%s", devicePath);
-      snprintf(deviceList[iFound].strComName, sizeof(deviceList[iFound].strComName), "%s", devicePath);
-      deviceList[iFound].iVendorId = CEC_VID;
-      deviceList[iFound].iProductId = CEC_VID;
-      deviceList[iFound].adapterType = ADAPTERTYPE_P8_EXTERNAL; // will be overridden when not doing a "quick scan" by the actual type
-      iFound++;
+    sscanf(pos, "vendor=%x ", &iVendor);
+
+    pos = strstr(infos, "product=");
+    if (pos == NULL)
+      continue;
+    sscanf(pos, "product=%x ", &iProduct);
+
+    if (iVendor != CEC_VID || (iProduct != CEC_PID && iProduct != CEC_PID2))
+      continue;
+
+    pos = strstr(infos, "ttyname=");
+    if (pos == NULL)
+      continue;
+    sscanf(pos, "ttyname=%s ", ttyname);
+
+    (void)snprintf(devicePath, sizeof(devicePath),
+      "/dev/tty%s", ttyname);
+
+    if (strDevicePath) {
+      char currStrDevicePath[512];
+      int port = 0;
+      int devaddr = 0;
+      memset(currStrDevicePath, 0, sizeof(currStrDevicePath));
+      memset(infos, 0, sizeof(infos));
+      (void)snprintf(sysctlname, sizeof(sysctlname),
+        "dev.umodem.%d.%%location", i);
+      if (sysctlbyname(sysctlname, infos, &infos_size,
+        NULL, 0) != 0)
+          break;
+
+      pos = strstr(infos, "port=");
+      if (pos == NULL)
+        continue;
+      sscanf(pos, "port=%d ", &port);
+
+      pos = strstr(infos, "devaddr=");
+      if (pos == NULL)
+        continue;
+      sscanf(pos, "devaddr=%d ", &devaddr);
+
+      (void)snprintf(currStrDevicePath, sizeof(currStrDevicePath),
+        "/dev/ugen%d.%d", port, devaddr);
+
+      if (strcmp(currStrDevicePath, strDevicePath) != 0)
+        continue;
     }
+    snprintf(deviceList[iFound].strComPath, sizeof(deviceList[iFound].strComPath), "%s", devicePath);
+    snprintf(deviceList[iFound].strComName, sizeof(deviceList[iFound].strComName), "%s", devicePath);
+    deviceList[iFound].iVendorId = iVendor;
+    deviceList[iFound].iProductId = iProduct;
+    deviceList[iFound].adapterType = ADAPTERTYPE_P8_EXTERNAL; // will be overridden when not doing a "quick scan" by the actual type
+    iFound++;
   }
 #else
   //silence "unused" warnings
