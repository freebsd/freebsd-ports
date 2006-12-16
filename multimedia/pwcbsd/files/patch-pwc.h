--- pwc.h	Thu Jun  8 20:27:39 2006
+++ pwc.h	Fri Dec 15 14:29:52 2006
@@ -133,7 +133,7 @@
 
 struct pwc_softc
 {
-   USBBASEDEVICE sc_dev; 
+   device_t sc_dev; 
    usbd_device_handle udev;
    usbd_interface_handle sc_iface;
    usbd_pipe_handle sc_videopipe;
