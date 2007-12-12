--- hw/dmx/dmxinput.c.orig	2007-12-12 17:52:53.000000000 +0000
+++ hw/dmx/dmxinput.c	2007-12-12 17:53:22.000000000 +0000
@@ -105,3 +105,14 @@
         if (!dmxInput->detached && dmxInput->updateWindowInfo)
             dmxInput->updateWindowInfo(dmxInput, type, pWindow);
 }
+
+int
+NewInputDeviceRequest(InputOption *options, DeviceIntPtr *pdev)
+{
+    return BadValue;
+}
+
+void
+DeleteInputDeviceRequest(DeviceIntPtr dev)
+{
+}
