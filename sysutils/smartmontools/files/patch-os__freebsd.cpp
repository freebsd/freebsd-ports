--- os_freebsd.cpp.orig	2023-03-14 20:01:29 UTC
+++ os_freebsd.cpp
@@ -56,8 +56,7 @@
 #endif
 
 #if (FREEBSDVER >= 800000)
-#include <libusb20_desc.h>
-#include <libusb20.h>
+#include <libusb.h>
 #elif defined(__DragonFly__)
 #include <bus/usb/usb.h>
 #include <bus/usb/usbhid.h>
@@ -2215,54 +2214,75 @@ static int usbdevlist(int busno,unsigned short & vendo
 static int usbdevlist(int busno,unsigned short & vendor_id,
   unsigned short & product_id, unsigned short & version)
 {
-#if (FREEBSDVER >= 800000) // libusb2 interface
-  struct libusb20_device *pdev = NULL;
-  struct libusb20_backend *pbe;
-  uint32_t matches = 0;
+#if (FREEBSDVER >= 800000) // libusb 1.0 interface
+  libusb_context *ctx = nullptr;
+  libusb_device **list = nullptr;
   char buf[128]; // do not change!
   char devname[128];
-  uint8_t n;
-  struct LIBUSB20_DEVICE_DESC_DECODED *pdesc;
+  int found = 0;
 
-  pbe = libusb20_be_alloc_default();
+  if (libusb_init(&ctx)) {
+    warnx("libusb_init: could not initialize libusb");
+    return 0;
+  }
 
-  while ((pdev = libusb20_be_device_foreach(pbe, pdev))) {
-    matches++;
+  ssize_t cnt = libusb_get_device_list(ctx, &list);
+  if (cnt < 0) {
+    warnx("libusb_get_device_list: could not list devices");
+    libusb_exit(ctx);
+    return 0;
+  }
 
-    if (libusb20_dev_open(pdev, 0)) {
-      warnx("libusb20_dev_open: could not open device");
-      return 0;
+  snprintf(devname, sizeof(devname), "umass%d", busno);
+
+  for (ssize_t i = 0; i < cnt && !found; i++) {
+    libusb_device * dev = list[i];
+    struct libusb_device_descriptor desc;
+    struct libusb_config_descriptor * config = nullptr;
+
+    if (libusb_get_device_descriptor(dev, &desc))
+      continue;
+
+    libusb_device_handle * handle = nullptr;
+    if (libusb_open(dev, &handle)) {
+      warnx("libusb_open: could not open device");
+      continue;
     }
 
-    pdesc=libusb20_dev_get_device_desc(pdev);
+    if (libusb_get_active_config_descriptor(dev, &config)) {
+      libusb_close(handle);
+      continue;
+    }
 
-    snprintf(devname, sizeof(devname),"umass%d:",busno);
-    for (n = 0; n != 255; n++) {
-      if (libusb20_dev_get_iface_desc(pdev, n, buf, sizeof(buf)))
-        break;
+    // Check the kernel driver of each interface declared by the active
+    // configuration.  On FreeBSD libusb_get_driver_np() takes the interface
+    // index (passed through to USB_GET_IFACE_DRIVER), not bInterfaceNumber.
+    for (uint8_t j = 0; j < config->bNumInterfaces && !found; j++) {
+      // returns the name of the kernel driver attached to this interface
+      if (libusb_get_driver_np(handle, j, buf, sizeof(buf)))
+        continue;
       if (buf[0] == 0)
         continue;
-      if(strncmp(buf,devname,strlen(devname))==0){
-        // found!
-        vendor_id = pdesc->idVendor;
-        product_id = pdesc->idProduct;
-        version = pdesc->bcdDevice;
-        libusb20_dev_close(pdev);
-        libusb20_be_free(pbe);
-        return 1;
+      if (!strcmp(buf, devname)) {
+        vendor_id = desc.idVendor;
+        product_id = desc.idProduct;
+        version = desc.bcdDevice;
+        found = 1;
       }
     }
 
-    libusb20_dev_close(pdev);
+    libusb_free_config_descriptor(config);
+    libusb_close(handle);
   }
 
-  if (matches == 0) {
+  if (cnt == 0) {
     printf("No device match or lack of permissions.\n");
   }
 
-  libusb20_be_free(pbe);
+  libusb_free_device_list(list, 1);
+  libusb_exit(ctx);
 
-  return false;
+  return found;
 #else // freebsd < 8.0 USB stack, ioctl interface
 
   int  i, a, rc;
