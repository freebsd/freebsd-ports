--- src/ifd/sys-bsd.c.orig	2008-07-27 02:54:36.000000000 -0700
+++ src/ifd/sys-bsd.c	2009-03-22 13:00:19.000000000 -0700
@@ -13,11 +13,13 @@
 #include "internal.h"
 #if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #include <sys/types.h>
+#ifndef ENABLE_LIBUSB
 #if defined(__DragonFly__)
 #include <bus/usb/usb.h>
 #else
 #include <dev/usb/usb.h>
 #endif
+#endif /* !ENABLE_LIBUSB */
 #include <sys/stat.h>
 #include <sys/ioctl.h>
 #include <sys/poll.h>
@@ -30,9 +32,16 @@
 #include <unistd.h>
 #include <errno.h>
 #include <openct/driver.h>
+#ifdef ENABLE_LIBUSB
+#include <usb.h>
+#endif
 
 #include "usb-descriptors.h"
 
+#ifdef ENABLE_LIBUSB
+struct usb_dev_handle *devices[128];
+#endif
+
 /*
  * Poll for presence of USB device
  */
@@ -45,6 +54,7 @@
 	return 1;
 }
 
+#ifndef ENABLE_LIBUSB
 typedef struct ep {
 	int ep_fd;
 } ep_t;
@@ -90,6 +100,7 @@
 		interfaces[interface][endpoint].ep_fd = 0;
 	}
 }
+#endif /* !ENABLE_LIBUSB */
 
 int ifd_sysdep_usb_bulk(ifd_device_t * dev, int ep, void *buffer, size_t len,
 			long timeout)
@@ -103,6 +114,16 @@
 	ct_debug("ifd_sysdep_usb_bulk: endpoint=%d direction=%d", endpoint,
 		 direction);
 	if (direction) {
+#ifdef ENABLE_LIBUSB
+		if ((bytes_to_process =
+		     usb_bulk_read(devices[dev->fd], ep, buffer, len,
+				   timeout)) < 0) {
+			ifd_debug(6, "ifd_sysdep_usb_bulk: read failed: %s",
+				  strerror(errno));
+			ct_error("usb_bulk read failed: %s", strerror(errno));
+			return IFD_ERROR_COMM_ERROR;
+		}
+#else
 		int one = 1;
 
 		if (open_ep(dev->name, 0, endpoint, O_RDONLY | O_NONBLOCK)) {
@@ -123,19 +144,28 @@
 			ct_error("usb_bulk read failed: %s", strerror(errno));
 			return IFD_ERROR_COMM_ERROR;
 		}
+#endif /* ENABLE_LIBUSB */
 		ct_debug("ifd_sysdep_usb_bulk: read %d bytes",
 			 bytes_to_process);
 		return bytes_to_process;
 	} else {
+#ifndef ENABLE_LIBUSB
 		if (open_ep(dev->name, 0, endpoint, O_WRONLY | O_NONBLOCK)) {
 			ct_debug("ifd_sysdep_usb_bulk: opening endpoint failed");
 			return -1;
 		}
+#endif /* !ENABLE_LIBUSB */
 
 		bytes_to_process = len;
 		if ((bytes_processed =
+#ifdef ENABLE_LIBUSB
+		     usb_bulk_write(devices[dev->fd], ep, buffer,
+				    bytes_to_process, timeout)
+#else
 		     write(interfaces[0][endpoint].ep_fd, buffer,
-			   bytes_to_process)) != bytes_to_process) {
+			   bytes_to_process)
+#endif /* ENABLE_LIBUSB */
+			    ) != bytes_to_process) {
 			ifd_debug(6, "ifd_sysdep_usb_bulk: write failed: %s",
 				  strerror(errno));
 			ct_error("usb_bulk write failed: %s", strerror(errno));
@@ -161,9 +191,11 @@
 				 size_t maxpacket, ifd_usb_capture_t ** capret)
 {
 	ifd_usb_capture_t *cap;
+#ifndef ENABLE_LIBUSB
 	int direction =
 	    (ep & IFD_USB_ENDPOINT_DIR_MASK) == IFD_USB_ENDPOINT_IN ? 1 : 0;
 	int endpoint = (ep & ~IFD_USB_ENDPOINT_DIR_MASK);
+#endif /* !ENABLE_LIBUSB */
 
 	if (!(cap = (ifd_usb_capture_t *) calloc(1, sizeof(*cap) + maxpacket))) {
 		ct_error("out of memory");
@@ -173,6 +205,7 @@
 	cap->endpoint = ep;
 	cap->maxpacket = maxpacket;
 
+#ifndef ENABLE_LIBUSB
 	if (!interfaces[0][endpoint].ep_fd) {
 		if (open_ep(dev->name, 0, endpoint, O_RDONLY | O_NONBLOCK)) {
 			ct_debug
@@ -180,6 +213,7 @@
 			return -1;
 		}
 	}
+#endif /* !ENABLE_LIBUSB */
 	*capret = cap;
 	return 0;
 }
@@ -187,8 +221,19 @@
 int ifd_sysdep_usb_capture(ifd_device_t * dev, ifd_usb_capture_t * cap,
 			   void *buffer, size_t len, long timeout)
 {
-	struct timeval begin;
 	int bytes_to_process = 0;
+#ifdef ENABLE_LIBUSB
+	if ((bytes_to_process =
+	     usb_interrupt_read(devices[dev->fd], cap->endpoint, buffer, len,
+				timeout)) < 0) {
+		ifd_debug(6,
+			  "ifd_sysdep_usb_capture: usb_interrupt_read failed: %s",
+			  strerror(errno));
+		ct_error("usb_bulk read failed: %s", strerror(errno));
+		return IFD_ERROR_COMM_ERROR;
+	}
+#else
+	struct timeval begin;
 	int direction =
 	    (cap->endpoint & IFD_USB_ENDPOINT_DIR_MASK) ==
 	    IFD_USB_ENDPOINT_IN ? 1 : 0;
@@ -215,6 +260,7 @@
 			return IFD_ERROR_COMM_ERROR;
 		}
 	} while (!bytes_to_process);
+#endif /* ENABLE_LIBUSB */
 	ct_debug("ifd_sysdep_usb_capture: read buffer[%d]=%s", bytes_to_process,
 		 ct_hexdump(buffer, bytes_to_process));
 	return bytes_to_process;
@@ -222,11 +268,13 @@
 
 int ifd_sysdep_usb_end_capture(ifd_device_t * dev, ifd_usb_capture_t * cap)
 {
+#ifndef ENABLE_LIBUSB
 	int direction =
 	    (cap->endpoint & IFD_USB_ENDPOINT_DIR_MASK) ==
 	    IFD_USB_ENDPOINT_IN ? 1 : 0;
 	int endpoint = (cap->endpoint & ~IFD_USB_ENDPOINT_DIR_MASK);
 	close_ep(0, endpoint);
+#endif /* !ENABLE_LIBUSB */
 	if (cap)
 		free(cap);
 	return 0;
@@ -240,9 +288,25 @@
 			   unsigned int index, void *data, size_t len,
 			   long timeout)
 {
-	struct usb_ctl_request ctrl;
 	int rc, val;
 
+#ifdef ENABLE_LIBUSB
+	ct_debug("ifd_sysdep_usb_control: dev->fd=%d handle=0x%x", dev->fd,
+		 devices[dev->fd]);
+	if ((rc =
+	     usb_control_msg(devices[dev->fd], requesttype, request, value,
+			     index, data, len, timeout)) < 0) {
+		ifd_debug(1, "usb_control_msg failed: %d", rc);
+		ct_error("usb_control_msg failed: %s(%d)",
+			 strerror(errno), errno);
+		return IFD_ERROR_COMM_ERROR;
+	}
+
+	ct_debug("ifd_sysdep_usb_control: return rc=%d", rc);
+	return rc;
+#else
+	struct usb_ctl_request ctrl;
+
 	ifd_debug(1, "BSD: ifd_sysdep_usb_control(0x%x)", request);
 	memset(&ctrl, 0, sizeof(ctrl));
 
@@ -282,14 +346,21 @@
 		ifd_debug(1, "BSD: CTRL RECV data %s",
 			  ct_hexdump(ctrl.ucr_data, ctrl.ucr_actlen));
 	return ctrl.ucr_actlen;
+#endif /* ENABLE_LIBUSB */
 }
 
 int ifd_sysdep_usb_set_configuration(ifd_device_t * dev, int config)
 {
-	int value, rc;
+	int rc;
+#ifdef ENABLE_LIBUSB
+	if ((rc = usb_set_configuration(devices[dev->fd], config)) < 0) {
+		ifd_debug(1, "usb_set_configuration failed: %d", rc);
+#else
+	int value;
 	value = config;
 	if ((rc = ioctl(dev->fd, USB_SET_CONFIG, &value)) < 0) {
 		ifd_debug(1, "USB_SET_CONFIG failed: %d", rc);
+#endif /* ENABLE_LIBUSB */
 		ct_error("usb_set_configuration failed: %s(%d)",
 			 strerror(errno), errno);
 		return IFD_ERROR_COMM_ERROR;
@@ -300,6 +371,10 @@
 int ifd_sysdep_usb_set_interface(ifd_device_t * dev, int ifc, int alt)
 {
 	int rc;
+#ifdef ENABLE_LIBUSB
+	if ((rc = usb_set_altinterface(devices[dev->fd], alt)) < 0) {
+		ifd_debug(1, "usb_set_altinterface failed: %d", rc);
+#else
 	struct usb_alt_interface {
 		int uai_config_index;
 		int uai_interface_index;
@@ -311,6 +386,7 @@
 	value.uai_alt_no = alt;
 	if ((rc = ioctl(dev->fd, USB_SET_ALTINTERFACE, &value)) < 0) {
 		ifd_debug(1, "USB_SET_ALTINTERFACE failed: %d", rc);
+#endif /* ENABLE_LIBUSB */
 		ct_error("usb_set_interface failed: %s(%d)",
 			 strerror(errno), errno);
 		return IFD_ERROR_COMM_ERROR;
@@ -320,22 +396,82 @@
 
 int ifd_sysdep_usb_claim_interface(ifd_device_t * dev, int interface)
 {
+#ifdef ENABLE_LIBUSB
+	int rc;
+
+	ct_debug("ifd_sysdep_usb_claim_interface: interface=%d", interface);
+	if ((rc = usb_claim_interface(devices[dev->fd], interface)) < 0) {
+		ifd_debug(1, "usb_clain_interface failed: %d", rc);
+		ct_error("usb_release_interface failed: %s(%d)",
+			 strerror(errno), errno);
+		return IFD_ERROR_COMM_ERROR;
+	}
+#else
 	ct_debug
 	    ("ifd_sysdep_usb_claim_interface: interface=%d (not yet implemented)",
 	     interface);
+#endif /* ENABLE_LIBUSB */
 	return 0;
 }
 
 int ifd_sysdep_usb_release_interface(ifd_device_t * dev, int interface)
 {
+#ifdef ENABLE_LIBUSB
+	int rc;
+
+	ct_debug("ifd_sysdep_usb_release_interface: interface=%d", interface);
+	if ((rc = usb_release_interface(devices[dev->fd], interface)) < 0) {
+		ifd_debug(1, "usb_release_interface failed: %d", rc);
+		ct_error("usb_release_interface failed: %s(%d)",
+			 strerror(errno), errno);
+		return IFD_ERROR_COMM_ERROR;
+	}
+#else
 	ct_debug
 	    ("ifd_sysdep_usb_release_interface: interface=%d (not yet implemented)",
 	     interface);
+#endif /* ENABLE_LIBUSB */
 	return 0;
 }
 
 int ifd_sysdep_usb_open(const char *device)
 {
+#ifdef ENABLE_LIBUSB
+	struct usb_bus *bus;
+	struct usb_device *dev;
+
+	ct_debug("ifd_sysdep_usb_open: name=%s", device);
+	ct_debug("ifd_sysdep_usb_open: usb_init()");
+	usb_init();
+	ct_debug("ifd_sysdep_usb_open: usb_find_busses()");
+	usb_find_busses();
+	ct_debug("ifd_sysdep_usb_open: usb_find_devices()");
+	usb_find_devices();
+
+	ct_debug("ifd_sysdep_usb_open: walk devices");
+	for (bus = usb_busses; bus; bus = bus->next) {
+		for (dev = bus->devices; dev; dev = dev->next) {
+			int i;
+
+			if (strcmp(dev->filename, device) != 0)
+				continue;
+
+			ct_debug
+			    ("ifd_sysdep_usb_open: found match name=%s device=%s",
+			     device, dev->filename);
+			for (i = 0; i < 128; i++) {
+				if (devices[i] == NULL) {
+					devices[i] = usb_open(dev);
+					ct_debug
+					    ("ifd_sysdep_usb_open: usb_open index=%d handle=0x%x",
+					     i, devices[i]);
+					return i;
+				}
+			}
+		}
+	}
+	return -1;
+#else
 #ifdef __OpenBSD__
 	char path[256];
 
@@ -345,6 +481,7 @@
 #else
 	return open(device, O_RDWR);
 #endif /* __OpenBSD__ */
+#endif /* ENABLE_LIBUSB */
 }
 
 int ifd_sysdep_usb_reset(ifd_device_t * dev)
@@ -358,6 +495,39 @@
  */
 int ifd_scan_usb(void)
 {
+#ifdef ENABLE_LIBUSB
+	struct usb_bus *bus;
+	struct usb_device *dev;
+	ifd_devid_t id;
+
+	usb_init();
+	usb_find_busses();
+	usb_find_devices();
+
+	id.type = IFD_DEVICE_TYPE_USB;
+	id.num = 2;
+	for (bus = usb_busses; bus; bus = bus->next) {
+		for (dev = bus->devices; dev; dev = dev->next) {
+			const char *driver;
+			char typedev[PATH_MAX];
+
+			id.val[0] = dev->descriptor.idVendor;
+			id.val[1] = dev->descriptor.idProduct;
+
+			/* FIXME: if we don't find a driver with vendor/product
+			 * then check for the interface type (ccid) and use
+			 * driver ccid... */
+
+			if (!(driver = ifd_driver_for_id(&id)))
+				continue;
+
+			snprintf(typedev, sizeof(typedev),
+				 "usb:%s", dev->filename);
+
+			ifd_spawn_handler(driver, typedev, -1);
+		}
+	}
+#else
 	int i, controller_fd;
 	char controller_devname[10];
 
@@ -421,6 +591,7 @@
 		}
 		close(controller_fd);
 	}
+#endif /* ENABLE_LIBUSB */
 	return 0;
 }
 #endif				/* __Net/Free/OpenBSD__ */
