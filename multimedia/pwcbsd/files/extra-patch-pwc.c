--- pwc.c.orig	2007-10-09 02:14:01.000000000 -0500
+++ pwc.c	2010-05-17 14:44:45.000000000 -0500
@@ -28,7 +28,8 @@
 #include "pwc-dec1.h"
 #include "pwc-dec23.h"
 
-static void pwc_isoc_handler(usbd_xfer_handle xfer, usbd_private_handle addr,usbd_status status);
+static void pwc_isoc_rx_callback(struct usb_xfer *xfer, usb_error_t err);
+static void pwc_isoc_handler(struct usb_xfer *xfer, void *addr);
 static void pwc_reset_buffers(struct pwc_softc *sc);
 static void pwc_free_buffers(struct pwc_softc *sc, int detach);
 
@@ -57,55 +58,70 @@
 	.d_mmap		= pwc_mmap,
 	.d_name		= "pwc",
 };
-					
-struct pwc_info {
-	struct usb_devno	devno;
-	int			type;
-	char			*name;
+
+static const struct usb_config pwc_config[MAX_ISO_BUFS] = {
+	[0] = {
+		.type = UE_ISOCHRONOUS,
+		.endpoint = UE_ADDR_ANY,
+		.direction = UE_DIR_IN,
+		.bufsize = 0,	/* use "wMaxPacketSize * frames" */
+		.frames = ISO_FRAMES_PER_DESC,
+		.flags = {.short_xfer_ok = 1,},
+		.callback = &pwc_isoc_rx_callback,
+	},
+
+	[1] = {
+		.type = UE_ISOCHRONOUS,
+		.endpoint = UE_ADDR_ANY,
+		.direction = UE_DIR_IN,
+		.bufsize = 0,	/* use "wMaxPacketSize * frames" */
+		.frames = ISO_FRAMES_PER_DESC,
+		.flags = {.short_xfer_ok = 1,},
+		.callback = &pwc_isoc_rx_callback,
+	},
 };
-static const struct pwc_info pwc_devs[] = {
-	{{ 0x0471, 0x0302 }, 645, "Philips PCA645VC" }, 
-	{{ 0x0471, 0x0303 }, 646, "Philips PCA646VC" },
-	{{ 0x0471, 0x0304 }, 646, "Askey VC010 type 2" },
-	{{ 0x0471, 0x0307 }, 675, "Philips PCVC675K (Vesta)" },
-	{{ 0x0471, 0x0308 }, 680, "Philips PCVC680K (Vesta Pro)" },
-	{{ 0x0471, 0x030C }, 690, "Philips PCVC690K (Vesta Pro Scan)" },
-	{{ 0x0471, 0x0310 }, 730, "Philips PCVC730K (ToUCam Fun)/PCVC830 (ToUCam II)" },
-	{{ 0x0471, 0x0311 }, 740, "Philips PCVC740K (ToUCam Pro)/PCVC840 (ToUCam II)" },
-	{{ 0x0471, 0x0312 }, 750, "Philips PCVC750K (ToUCam Pro Scan)" },
-	{{ 0x0471, 0x0313 }, 720, "Philips PCVC720K/40 (ToUCam XS)" },
-	{{ 0x0471, 0x0329 }, 740, "Philips SPC900NC" },
-	{{ 0x069A, 0x0001 }, 645, "Askey VC010 type 1" }, 
-	{{ 0x046D, 0x08B0 }, 740, "Logitech QuickCam Pro 3000" }, 
-	{{ 0x046D, 0x08B1 }, 740, "Logitech QuickCam Notebook Pro" }, 
-	{{ 0x046D, 0x08B2 }, 740, "Logitech QuickCam Pro 4000" }, 
-	{{ 0x046D, 0x08B3 }, 740, "Logitech QuickCam Zoom" }, 
-	{{ 0x046D, 0x08B4 }, 740, "Logitech QuickCam Zoom (new model)" }, 
-	{{ 0x046D, 0x08B5 }, 740, "Logitech QuickCam Orbit/Sphere" }, 
-	{{ 0x046D, 0x08B6 }, 730, "Logitech QuickCam (reserved ID)" }, 
-	{{ 0x046D, 0x08B7 }, 730, "Logitech QuickCam (reserved ID)" }, 
-	{{ 0x046D, 0x08B8 }, 730, "Logitech QuickCam (reserved ID)" }, 
-	{{ 0x055D, 0x9000 }, 675, "Samsung MPC-C10" }, 
-	{{ 0x055D, 0x9001 }, 675, "Samsung MPC-C30" },
-	{{ 0x055D, 0x9002 }, 740, "Samsung SNC-35E" },
-	{{ 0x041E, 0x400C }, 730, "Creative Labs Webcam 5" }, 
-	{{ 0x041E, 0x4011 }, 740, "Creative Labs Webcam Pro Ex" }, 
-	{{ 0x04CC, 0x8116 }, 730, "Sotec Afina Eye"  }, 
-	{{ 0x06BE, 0x8116 }, 750, "AME Co. Afina Eye" }, 
-	{{ 0x0d81, 0x1910 }, 740, "Visionite VCS-UC300" }, 
-	{{ 0x0d81, 0x1900 }, 730, "Visionite VCS-UM100" },
+
+static const struct usb_device_id pwc_devs[] = {
+  {USB_VPI(0x0471, 0x0302, 645)}, /* Philips PCA645VC */
+  {USB_VPI(0x0471, 0x0303, 646)}, /* Philips PCA646VC */
+  {USB_VPI(0x0471, 0x0304, 646)}, /* Askey VC010 type 2 */
+  {USB_VPI(0x0471, 0x0307, 675)}, /* Philips PCVC675K (Vesta) */
+  {USB_VPI(0x0471, 0x0308, 680)}, /* Philips PCVC680K (Vesta Pro) */
+  {USB_VPI(0x0471, 0x030C, 690)}, /* Philips PCVC690K (Vesta Pro Scan) */
+  {USB_VPI(0x0471, 0x0310, 730)}, /* Philips PCVC730K (ToUCam Fun)/PCVC830 (ToUCam II) */
+  {USB_VPI(0x0471, 0x0311, 740)}, /* Philips PCVC740K (ToUCam Pro)/PCVC840 (ToUCam II) */
+  {USB_VPI(0x0471, 0x0312, 750)}, /* Philips PCVC750K (ToUCam Pro Scan) */
+  {USB_VPI(0x0471, 0x0313, 720)}, /* Philips PCVC720K/40 (ToUCam XS) */
+  {USB_VPI(0x0471, 0x0329, 740)}, /* Philips SPC900NC */
+  {USB_VPI(0x069A, 0x0001, 645)}, /* Askey VC010 type 1 */
+  {USB_VPI(0x046D, 0x08B0, 740)}, /* Logitech QuickCam Pro 3000 */
+  {USB_VPI(0x046D, 0x08B1, 740)}, /* Logitech QuickCam Notebook Pro */
+  {USB_VPI(0x046D, 0x08B2, 740)}, /* Logitech QuickCam Pro 4000 */
+  {USB_VPI(0x046D, 0x08B3, 740)}, /* Logitech QuickCam Zoom */
+  {USB_VPI(0x046D, 0x08B4, 740)}, /* Logitech QuickCam Zoom (new model) */
+  {USB_VPI(0x046D, 0x08B5, 740)}, /* Logitech QuickCam Orbit/Sphere */
+  {USB_VPI(0x046D, 0x08B6, 730)}, /* Logitech QuickCam (reserved ID) */
+  {USB_VPI(0x046D, 0x08B7, 730)}, /* Logitech QuickCam (reserved ID) */
+  {USB_VPI(0x046D, 0x08B8, 730)}, /* Logitech QuickCam (reserved ID) */
+  {USB_VPI(0x055D, 0x9000, 675)}, /* Samsung MPC-C10 */
+  {USB_VPI(0x055D, 0x9001, 675)}, /* Samsung MPC-C30 */
+  {USB_VPI(0x055D, 0x9002, 740)}, /* Samsung SNC-35E */
+  {USB_VPI(0x041E, 0x400C, 730)}, /* Creative Labs Webcam 5 */
+  {USB_VPI(0x041E, 0x4011, 740)}, /* Creative Labs Webcam Pro Ex */
+  {USB_VPI(0x04CC, 0x8116, 730)}, /* Sotec Afina Eye  */
+  {USB_VPI(0x06BE, 0x8116, 750)}, /* AME Co. Afina Eye */
+  {USB_VPI(0x0d81, 0x1910, 740)}, /* Visionite VCS-UC300 */
+  {USB_VPI(0x0d81, 0x1900, 730)}, /* Visionite VCS-UM100 */
 };
-#define pwc_lookup(v, p) ((const struct pwc_info *)usb_lookup(pwc_devs, v, p))
-#define PWCUNIT(n) (minor(n))
 
-static device_probe_t pwc_match;
+static device_probe_t pwc_probe;
 static device_attach_t pwc_attach;
 static device_detach_t pwc_detach;
 
 static devclass_t pwc_devclass;
 
 static device_method_t pwc_methods[] = {
-	DEVMETHOD(device_probe, pwc_match),
+	DEVMETHOD(device_probe, pwc_probe),
 	DEVMETHOD(device_attach, pwc_attach),
 	DEVMETHOD(device_detach, pwc_detach),
 	{0,0},
@@ -120,41 +136,25 @@
 MODULE_DEPEND(pwc, usb, 1, 1, 1);
 
 static int
-pwc_match(device_t self)
+pwc_probe(device_t self)
 {
-        struct usb_attach_arg *uaa = device_get_ivars(self);
-	usb_interface_descriptor_t *id;
+	struct usb_attach_arg *uaa = device_get_ivars(self);
 
-	Trace(TRACE_PROBE,"pwc_match: vendor=0x%x, product=0x%x release=%04x\n",uaa->vendor, uaa->product,uaa->release);
-	
-	if(pwc_lookup(uaa->vendor, uaa->product) == NULL)
-		return UMATCH_NONE;
+	Trace(TRACE_PROBE,"pwc_probe:\n");
+
+	if (uaa->usb_mode != USB_MODE_HOST)
+		return (ENXIO);
 
-	/* Driver loaded when device was already plugged in, we have to claim all interfaces or get none... */
-	if(uaa->usegeneric)
-		return  UMATCH_VENDOR_PRODUCT;
-	
-	/* We don't want all interfaces */
-	if(uaa->iface == NULL) 
-		return UMATCH_NONE;
-	
-	id = usbd_get_interface_descriptor(uaa->iface);
-	if(id == NULL) {
-		printf("pwc: failed to get interface descriptor\n");
-		return UMATCH_NONE;
-	}
-	
-        Trace(TRACE_PROBE,"pwc_match: iface=%d\n",id->bInterfaceNumber);
-	
 	/* Interface 0 is the video interface
 	 * Interface 1 is supposed to be audiocontrol
 	 * Interface 2 is supposed to be audio
 	 */
-	if(id->bInterfaceNumber != 0)
-		return UMATCH_NONE;
-	
-	return  UMATCH_VENDOR_PRODUCT;
-			
+	if (uaa->info.bIfaceIndex != 0)
+		return (ENXIO);
+
+	return (usbd_lookup_id_by_uaa(pwc_devs, sizeof(pwc_devs), uaa));
+
+	return (0); /* success */
 }
 
 static int
@@ -162,43 +162,26 @@
 {
 	struct pwc_softc *sc = device_get_softc(self);
 	struct usb_attach_arg *uaa = device_get_ivars(self);
-	char devinfo[1024];
-	const char *tmpstr;
-	const struct pwc_info *info;
 	char *sizenames[PSZ_MAX] = { "sqcif", "qsif", "qcif", "sif", "cif", "vga" };
-	int i, err;
+	const char *tmpstr;
+	int i;
 
-	info = pwc_lookup(uaa->vendor, uaa->product);
-	if(info == NULL) {
-		printf("%s: attach error vendor/product mismatch (vendor=0x%x product=0x%x)\n",
-			device_get_nameunit(sc->sc_dev),uaa->vendor,uaa->product);
-		return ENXIO;
-	}
+	device_set_usb_desc(self);
 
-	usbd_devinfo(uaa->device, 0, devinfo);
 	sc->sc_dev = self;
-	device_set_desc_copy(self, devinfo);
-	device_printf(self, "%s\n", devinfo);
-
-	err = usbd_device2interface_handle(uaa->device,0,&sc->sc_iface);
-	if(err) {
-		printf("%s: failed to get interface handle\n",device_get_nameunit(sc->sc_dev));
-		return ENXIO;
-	}
 
 	sc->udev = uaa->device;
-	sc->type = info->type;
-	sc->name = info->name;
-	sc->release = uaa->release;
+	sc->type = USB_GET_DRIVER_INFO(uaa);
+	sc->release = uaa->info.bcdDevice;
 	sc->power_save = 0;
-	
+
 	strcpy(sc->serial,"000-000-000-000");
 	
-	if(uaa->vendor == 0x046D) {
-		if(uaa->product == 0x08B4) {
+	if(uaa->info.idVendor == 0x046D) {
+		if(uaa->info.idProduct == 0x08B4) {
 			sc->power_save = 1;
 		}
-		else if(uaa->product == 0x08B5) {
+		else if(uaa->info.idProduct == 0x08B5) {
 		
 			/* Logitech QuickCam Orbit */
 			sc->features |= FEATURE_MOTOR_PANTILT;
@@ -215,6 +198,8 @@
 	resource_string_value("pwc",device_get_unit(self),"devname",&tmpstr);
 	sc->sc_dev_t = make_dev(&pwc_cdevsw, device_get_unit(self),UID_ROOT, GID_OPERATOR,
 				0666, "%s%d",tmpstr,device_get_unit(self));
+	if (sc->sc_dev_t != NULL)
+		sc->sc_dev_t->si_drv1 = sc;
 	
 	resource_int_value("pwc",device_get_unit(self),"power_save",&sc->power_save);
 
@@ -273,7 +258,6 @@
 	resource_int_value("pwc",device_get_unit(self),"pad",&sc->pwc_pad);
 
 	pwc_construct(sc);
-	printf("%s: %s USB webcam\n",device_get_nameunit(sc->sc_dev),sc->name);
 
 	if(pwc_get_cmos_sensor(sc, &i) >= 0) {
 	
@@ -299,7 +283,6 @@
 	if(sc->power_save)
 		pwc_camera_power(sc, 0);
 
-	usbd_add_drv_event(USB_EVENT_DRIVER_ATTACH, sc->udev,sc->sc_dev);
 	return 0;
 }
 
@@ -309,12 +292,8 @@
 	struct pwc_softc *sc = device_get_softc(self);
 
 	Trace(TRACE_PROBE,"pwc_detach: sc=%p\n",sc);
-	
-	if(sc->sc_videopipe != NULL) {
-		usbd_abort_pipe(sc->sc_videopipe);
-		usbd_close_pipe(sc->sc_videopipe);
-		sc->sc_videopipe = NULL;
-	}
+
+	usbd_transfer_unsetup(sc->sc_xfer, MAX_ISO_BUFS);
 
 	sc->error_status = EPIPE;
 
@@ -334,21 +313,17 @@
 	
 	mtx_destroy(&sc->ptrlock);
 	pwc_free_buffers(sc,1);
-	usbd_add_drv_event(USB_EVENT_DRIVER_DETACH, sc->udev,sc->sc_dev);
 	return 0;
 }
 
 int
 pwc_open(struct cdev *dev, int flag, int mode, struct thread *p)
 {
-	struct pwc_softc *sc;
+	struct pwc_softc *sc = dev->si_drv1;
 	int i,err;
-	int unit = PWCUNIT(dev);
-	
-	sc = devclass_get_softc(pwc_devclass,unit);
-	if(sc == NULL)
-		return ENXIO;
-	
+#ifdef USB_DEBUG
+	int unit = device_get_unit(sc->sc_dev);
+#endif
 	Trace(TRACE_OPEN,"pwc_open: flag=%d, mode=%d, unit=%d\n",flag, mode, unit);
 
 	if(sc->error_status == EPIPE)
@@ -419,23 +394,6 @@
 	for (i = 0; i < sc->pwc_mbufs; i++)
 		sc->image_used[i] = 0;
 
-	/* Allocate iso transfers */
-	for (i = 0; i < MAX_ISO_BUFS; i++) {
-		sc->sbuf[i].sc = sc;
-		sc->sbuf[i].xfer = usbd_alloc_xfer(sc->udev); 
-		
-		if(sc->sbuf[i].xfer == NULL) {
-			printf("%s: Failed to allocate transfer\n",device_get_nameunit(sc->sc_dev));
-			goto bad;
-		}
-		
-		sc->sbuf[i].data = usbd_alloc_buffer(sc->sbuf[i].xfer, ISO_BUFFER_SIZE);
-		if(sc->sbuf[i].data == NULL) {
-			printf("%s: Failed to allocate transferbuffer\n",device_get_nameunit(sc->sc_dev));
-			goto bad;
-		}
-	}
-		
 	sc->state = 0;
 	sc->vframe_count = 0;
 	sc->vframes_dumped = 0;
@@ -476,10 +434,10 @@
 int
 pwc_close(struct cdev *dev, int flag, int mode, struct thread *p)
 {
-	struct pwc_softc *sc;
-	int unit = PWCUNIT(dev);
-	
-	sc = devclass_get_softc(pwc_devclass, unit);
+	struct pwc_softc *sc = dev->si_drv1;
+#ifdef USB_DEBUG
+	int unit = device_get_unit(sc->sc_dev);
+#endif
 	Trace(TRACE_OPEN,"pwc_close: flag=%d, mode=%d, unit=%d\n", flag, mode, unit);
 
 	/* Dump statistics, but only if a reasonable amount of frames were
@@ -495,19 +453,14 @@
 		pwc_dec1_exit();
 	else
 		pwc_dec23_exit();	/* Timon & Kiara */
-	
-	if(sc->sc_videopipe != NULL) {
-		usbd_abort_pipe(sc->sc_videopipe);
-		usbd_close_pipe(sc->sc_videopipe);
-		sc->sc_videopipe = NULL;
-	}
 
 	pwc_free_buffers(sc,0);
 	
 	/* Turn off LEDS and power down camera, but only when not unplugged */
 	if(sc->error_status != EPIPE) {
-		
-		usbd_set_interface(sc->sc_iface, 0);
+
+		usbd_set_alt_interface_index(sc->udev, sc->sc_iface_index, 0);
+
 		pwc_set_leds(sc,0,0);
 		
 		if(sc->power_save) {
@@ -523,15 +476,16 @@
 int
 pwc_read(struct cdev *dev, struct uio *uio, int flag)
 {
-	struct pwc_softc *sc;
-	int unit = PWCUNIT(dev);
+	struct pwc_softc *sc = dev->si_drv1;
+#ifdef USB_DEBUG
+	int unit = device_get_unit(sc->sc_dev);
+#endif
         int bytes_to_read;
 	int count = uio->uio_resid;
 	int err;
 
 	Trace(TRACE_READ,"pwc_read: flag=%d, unit=%d\n", flag, unit);
 
-	sc = devclass_get_softc(pwc_devclass, unit);
 	if (sc->error_status)
 		return sc->error_status;
 
@@ -565,7 +519,7 @@
 	if(count + sc->image_read_pos > bytes_to_read)
 		count = bytes_to_read - sc->image_read_pos;
 	
-	Trace(TRACE_READ_VERBOSE, "pwc_read: wants: %d bytes, reading: %d bytes\n",uio->uio_resid,count);
+	Trace(TRACE_READ_VERBOSE, "pwc_read: wants: %d bytes, reading: %d bytes\n",(int)uio->uio_resid,count);
 
 	err = uiomove(sc->images[sc->fill_image].bufmem + sc->image_read_pos,count,uio);
 	if(err)
@@ -583,10 +537,9 @@
 int
 pwc_ioctl(struct cdev *dev, u_long cmd, caddr_t addr, int flag, struct thread *p)
 {
-	struct pwc_softc *sc;
-	int unit = PWCUNIT(dev);
+	struct pwc_softc *sc = dev->si_drv1;
+	int unit = device_get_unit(sc->sc_dev);
 
-	sc = devclass_get_softc(pwc_devclass, unit);
 	if (sc->error_status)
 		return sc->error_status;
 	
@@ -596,11 +549,9 @@
 int
 pwc_poll(struct cdev *dev, int events, struct thread *p)
 {
-	struct pwc_softc *sc;
-	int unit = PWCUNIT(dev);
+	struct pwc_softc *sc = dev->si_drv1;
 	int revents = 0;
 	
-	sc = devclass_get_softc(pwc_devclass, unit);
 	if(sc->error_status)
 		return sc->error_status;
 
@@ -625,16 +576,17 @@
 }
 
 int
+#ifdef D_VERSION_03
+pwc_mmap(struct cdev *dev, vm_ooffset_t offset, vm_paddr_t *paddr, int nprot,
+	 __unused vm_memattr_t *memattr)
+#else
 pwc_mmap(struct cdev *dev, vm_offset_t offset, vm_paddr_t *paddr, int nprot)
+#endif
 {
 #ifdef USE_MMAP
-	struct pwc_softc *sc;
-	int unit = PWCUNIT(dev);
+	struct pwc_softc *sc = dev->si_drv1;
+	int unit = device_get_unit(sc->sc_dev);
 
-	sc = devclass_get_softc(pwc_devclass, unit);
-	if(sc == NULL)
-		return ENXIO;
-	
 	if (sc->error_status)
 		return sc->error_status;
 
@@ -652,16 +604,10 @@
 int
 pwc_try_video_mode(struct pwc_softc *sc, int width, int height, int new_fps, int new_compression, int new_snapshot)
 {
-	usb_endpoint_descriptor_t *edesc = NULL;
-	u_int8_t nendpt;
-	int i, j, err, ret;
-
-	if(sc->sc_videopipe != NULL) {
-		usbd_abort_pipe(sc->sc_videopipe);
-		usbd_close_pipe(sc->sc_videopipe);
-		sc->sc_videopipe = NULL;
-	}
-	
+	int i, err, ret;
+
+	usbd_transfer_unsetup(sc->sc_xfer, MAX_ISO_BUFS);
+
 	pwc_reset_buffers(sc);
 	
 	/* Try to set video mode... if that fails fallback to previous mode  */
@@ -678,52 +624,21 @@
 	sc->drop_frames++; /* try to avoid garbage during switch */
 	sc->vsync = 0;
 
-	err = usbd_set_interface(sc->sc_iface,sc->valternate);
-	if(err != USBD_NORMAL_COMPLETION) {
+	err = usbd_set_alt_interface_index(sc->udev, sc->sc_iface_index, sc->valternate);
+	if(err != USB_ERR_NORMAL_COMPLETION) {
 		printf("%s: Failed to set alternate interface to: %d (%d)\n",device_get_nameunit(sc->sc_dev),sc->valternate,err);
 		return -err;
 	}
 
-	err = usbd_endpoint_count(sc->sc_iface, &nendpt);
-        if(err != USBD_NORMAL_COMPLETION) {
-		printf("%s: Failed to get endpoint count (%d)\n",device_get_nameunit(sc->sc_dev),err);
-		return -err;
-	}
-	for (i = 0; i < nendpt; i++) {
-		edesc = usbd_interface2endpoint_descriptor(sc->sc_iface, i);
-		if(edesc != NULL && UE_GET_ADDR(edesc->bEndpointAddress) == sc->vendpoint)
-			break;
-	}
-	if(i == nendpt) {
-		printf("%s: Failed to find videoendpoint\n",device_get_nameunit(sc->sc_dev));
-		return -EINVAL;
-	}
-	
-	sc->vmax_packet_size = UGETW(edesc->wMaxPacketSize);
-	if(sc->vmax_packet_size < 0 || sc->vmax_packet_size > ISO_MAX_FRAME_SIZE) {
-		printf("%s: Invalid packetsize (%d) for endpoint %d\n",device_get_nameunit(sc->sc_dev),
-			sc->vmax_packet_size,edesc->bEndpointAddress);
-		return -EINVAL;
-	}
-		 
-	err = usbd_open_pipe(sc->sc_iface,edesc->bEndpointAddress, 0, &sc->sc_videopipe);
-	if(err != USBD_NORMAL_COMPLETION) {
-		printf("%s: Failed to open videopipe (%d)\n",device_get_nameunit(sc->sc_dev),err);
+	/* Allocate iso transfers */
+	if (usbd_transfer_setup(sc->udev, &sc->sc_iface_index, sc->sc_xfer,
+	    pwc_config, MAX_ISO_BUFS, sc, &Giant)) {
+		printf("%s: Failed to setup USB transfers\n", device_get_nameunit(sc->sc_dev));
 		return -err;
 	}
 
 	for (i = 0; i < MAX_ISO_BUFS; i++) {
-		
-		for(j = 0; j < ISO_FRAMES_PER_DESC; ++j)
-			sc->sbuf[i].sizes[j] = sc->vmax_packet_size;
-
-		usbd_setup_isoc_xfer(sc->sbuf[i].xfer, sc->sc_videopipe,
-				     &sc->sbuf[i],sc->sbuf[i].sizes,
-				     ISO_FRAMES_PER_DESC,
-				     USBD_NO_COPY|USBD_SHORT_XFER_OK,
-				     pwc_isoc_handler);
-		
-		usbd_transfer(sc->sbuf[i].xfer);
+		usbd_transfer_start(sc->sc_xfer[i]);
 	}
 	
 	if(sc->state & PWC_INIT)
@@ -767,37 +682,41 @@
 }
 
 static void
-pwc_isoc_handler(usbd_xfer_handle xfer, usbd_private_handle addr,usbd_status status)
+pwc_isoc_rx_callback(struct usb_xfer *xfer, usb_error_t err)
 {
-   	struct pwc_iso_buf *req = addr;
-	struct pwc_softc *sc = req->sc;
+	uint8_t i;
+
+	switch(USB_GET_STATE(xfer)) {
+	case USB_ST_TRANSFERRED:
+		pwc_isoc_handler(xfer, xfer->priv_sc);
+
+		/* FALLTHROUGH */
+
+	case USB_ST_SETUP:
+	tr_setup:
+		for (i = 0; i != xfer->max_frame_count; i++)
+			xfer->frlengths[i] = xfer->max_frame_size;
+
+		xfer->nframes = xfer->max_frame_count;
+		usbd_transfer_submit(xfer);
+		break;
+	default:
+		if (xfer->error != USB_ERR_CANCELLED)
+			goto tr_setup;
+		break;
+	}
+}
+
+static void
+pwc_isoc_handler(struct usb_xfer *xfer, void *addr)
+{
+	struct pwc_softc *sc = addr;
 	struct pwc_frame_buf *fbuf;
 	unsigned char *fillptr = NULL;
-	u_int32_t count;
 	int awake = 0;
 	int i;
-	
-	usbd_get_xfer_status(xfer, NULL, NULL, &count, NULL);
-	Trace(TRACE_ISOC_VERBOSE, "pwc_isoc_handler: status=%d count=%u\n",status,count);
-
-	if (status == USBD_CANCELLED) {
-		Trace(TRACE_ISOC, "pwc_isoc_handler: status = cancelled\n");
-		return;
-	}
-	if(status != USBD_NORMAL_COMPLETION) {
-
-		Trace(TRACE_ISOC, "pwc_isoc_handler called with status: %d\n",status);
-
-		if (++sc->visoc_errors > MAX_ISOC_ERRORS) {
-			
-			if(sc->error_status != EIO)
-				printf("%s: Too many ISOC errors, bailing out.\n",device_get_nameunit(sc->sc_dev));
 
-			sc->error_status = EIO;
-			awake = 1;
-		}
-		goto handler_end; // ugly, but practical
-	}
+	Trace(TRACE_ISOC_VERBOSE, "pwc_isoc_handler: count=%u\n", xfer->actlen);
 
 	/* Reset ISOC error counter. We did get here, after all. */
 	sc->visoc_errors = 0;
@@ -816,8 +735,8 @@
 		/* XXX there is no individual framestatus in FreeBSD usbstack
 		 * so just assume all frames are good
 		 */
-		u_int16_t flen = req->sizes[i];
-		unsigned char *iso_buf = req->data + sc->vmax_packet_size * i;
+		u_int16_t flen = xfer->frlengths[i];
+		u_int32_t iso_buf = xfer->max_frame_size * i;
 
 		if (flen > 0) { /* if valid data... */
 			if(sc->vsync > NOCOPY) { /* ...and we are not sync-hunting... */
@@ -830,7 +749,7 @@
 					sc->vframes_error++;
 				}
 				else {
-					memcpy(fillptr, iso_buf, flen);
+					usbd_copy_out(xfer->frbuffers, iso_buf, fillptr, flen);
 					fillptr += flen;
 				}
 			}
@@ -943,7 +862,6 @@
 		sc->vlast_packet_size = flen;
 
 	}
-handler_end:
 	if(awake) {
 		if(sc->state & PWC_ASLEEP) {
 			wakeup(sc);
@@ -953,16 +871,6 @@
 			selwakeuppri(&sc->rsel, PZERO);
 		}
 	}
-	/* setup size for next transfer */
-	for (i = 0; i < ISO_FRAMES_PER_DESC; i++)
-		req->sizes[i] = sc->vmax_packet_size;
-	
-	usbd_setup_isoc_xfer(xfer, sc->sc_videopipe, req, req->sizes,
-			     ISO_FRAMES_PER_DESC,
-			     USBD_NO_COPY|USBD_SHORT_XFER_OK,
-			     pwc_isoc_handler);
-
-	usbd_transfer(xfer);
 }
 
 int
@@ -1050,6 +958,9 @@
 {
 	int i;
 	Trace(TRACE_MEMORY, "Entering free_buffers(%p).\n", sc);
+
+	usbd_transfer_unsetup(sc->sc_xfer, MAX_ISO_BUFS);
+
 	if (sc->fbuf != NULL) {
 		for (i = 0; i < sc->pwc_fbufs; i++) {
 			if (sc->fbuf[i].data != NULL) {
@@ -1074,13 +985,6 @@
 		free(sc->image_data,M_USBDEV);
 		sc->image_data = NULL;
 	}
-
-	for (i = 0; i < MAX_ISO_BUFS; i++) {
-		if (sc->sbuf[i].xfer != NULL) {
-			usbd_free_xfer(sc->sbuf[i].xfer); /* implicit buffer free */
-			sc->sbuf[i].xfer = NULL;
-		}
-	}
 }
 
-DRIVER_MODULE(pwc, uhub, pwc_driver, pwc_devclass, usbd_driver_load, 0);
+DRIVER_MODULE(pwc, uhub, pwc_driver, pwc_devclass, NULL, 0);
