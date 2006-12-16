--- pwc.c	Sun Sep 24 06:58:43 2006
+++ pwc.c	Fri Dec 15 14:37:13 2006
@@ -149,8 +149,9 @@
 
 	info = pwc_lookup(uaa->vendor, uaa->product);
 	if(info == NULL) {
-		printf("%s: attach error vendor/product mismatch (vendor=0x%x product=0x%x)\n",
-			USBDEVNAME(sc->sc_dev),uaa->vendor,uaa->product);
+		device_printf(sc->sc_dev, 
+            "attach error vendor/product mismatch (vendor=0x%x product=0x%x)\n",
+			uaa->vendor,uaa->product);
 		USB_ATTACH_ERROR_RETURN;
 	}
 
@@ -159,7 +160,7 @@
 
 	err = usbd_device2interface_handle(uaa->device,0,&sc->sc_iface);
 	if(err) {
-		printf("%s: failed to get interface handle\n",USBDEVNAME(sc->sc_dev));
+		device_printf(sc->sc_dev, "failed to get interface handle\n");
 		USB_ATTACH_ERROR_RETURN;
 	}
 
@@ -192,7 +193,7 @@
 		}
 	}
 
-	mtx_init(&sc->ptrlock,USBDEVNAME(sc->sc_dev),NULL,MTX_DEF);
+	mtx_init(&sc->ptrlock,device_get_name(sc->sc_dev),NULL,MTX_DEF);
 
 	tmpstr = "video";
 	resource_string_value("pwc",device_get_unit(self),"devname",&tmpstr);
@@ -256,7 +257,7 @@
 	resource_int_value("pwc",device_get_unit(self),"pad",&sc->pwc_pad);
 
 	pwc_construct(sc);
-	printf("%s: %s USB webcam\n",USBDEVNAME(sc->sc_dev),sc->name);
+	device_printf(sc->sc_dev, "%s USB webcam\n", sc->name);
 
 	if(pwc_get_cmos_sensor(sc, &i) >= 0) {
 	
@@ -274,7 +275,8 @@
 		default:    tmpstr = "unknown type of sensor"; break;
 		}
 		
-		printf("%s: This camera is equipped with a %s (%d)\n",USBDEVNAME(sc->sc_dev),tmpstr, i);
+		device_printf(sc->sc_dev, "This camera is equipped with a %s (%d)\n",
+            tmpstr, i);
 	}
 	
 	pwc_set_leds(sc, 0, 0);
@@ -308,7 +310,7 @@
 			sc->state &= ~PWC_POLL;
 			selwakeuppri(&sc->rsel,PZERO);
 		}
-		printf("%s: Disconnected while webcam is in use!\n",USBDEVNAME(sc->sc_dev));
+		device_printf(sc->sc_dev, "Disconnected while webcam is in use!\n");
 	}
 	
 	if(sc->sc_dev_t != NULL)
@@ -345,7 +347,8 @@
 	if (sc->power_save) {
 		err = pwc_camera_power(sc, 1);
 		if (err < 0)
-			printf("%s: Failed to restore power to the camera! (%d)\n", USBDEVNAME(sc->sc_dev),-err);
+			device_printf(sc->sc_dev, 
+                "Failed to restore power to the camera! (%d)\n", -err);
 	}
 
 	pwc_set_leds(sc, sc->led_on, sc->led_off);
@@ -354,7 +357,8 @@
 	/* Allocate frame buffer structure */
 	sc->fbuf = malloc(sc->pwc_fbufs * sizeof(struct pwc_frame_buf), M_USBDEV, M_WAITOK);
 	if (sc->fbuf == NULL) {
-		printf("%s: Failed to allocate frame buffer structure.\n",USBDEVNAME(sc->sc_dev));
+		device_printf(sc->sc_dev, 
+            "Failed to allocate frame buffer structure.\n");
 		goto bad;
 	}
 	memset(sc->fbuf, 0, sc->pwc_fbufs * sizeof(struct pwc_frame_buf));
@@ -364,7 +368,7 @@
 			
 		sc->fbuf[i].data = malloc(PWC_FRAME_SIZE,M_USBDEV,M_WAITOK);
 		if (sc->fbuf[i].data == NULL) {
-			printf("%s: Failed to allocate frame buffer\n", USBDEVNAME(sc->sc_dev));
+			device_printf(sc->sc_dev, "Failed to allocate frame buffer\n");
 			goto bad;
 		}
 		memset(sc->fbuf[i].data, 128, PWC_FRAME_SIZE);
@@ -376,7 +380,7 @@
 		sc->decompress_data = malloc(sizeof(struct pwc_dec23_private), M_USBDEV, M_WAITOK);/* Timon & Kiara */
 
 	if(sc->decompress_data == NULL) {
-		printf("%s: Failed to allocate decompress table.\n",USBDEVNAME(sc->sc_dev));
+		device_printf(sc->sc_dev, "Failed to allocate decompress table.\n");
 		goto bad;
 	}
 	
@@ -384,7 +388,7 @@
 	if(sc->image_data == NULL) {
 		sc->image_data = malloc(sc->pwc_mbufs * round_page(sc->len_per_image), M_USBDEV, M_WAITOK);
 		if(sc->image_data == NULL) {
-			printf("%s: Failed to allocate image buffers\n",USBDEVNAME(sc->sc_dev));
+			device_printf(sc->sc_dev, "Failed to allocate image buffers\n");
 			goto bad;
 		}
 	}
@@ -404,13 +408,13 @@
 		sc->sbuf[i].xfer = usbd_alloc_xfer(sc->udev); 
 		
 		if(sc->sbuf[i].xfer == NULL) {
-			printf("%s: Failed to allocate transfer\n",USBDEVNAME(sc->sc_dev));
+			device_printf(sc->sc_dev, "Failed to allocate transfer\n");
 			goto bad;
 		}
 		
 		sc->sbuf[i].data = usbd_alloc_buffer(sc->sbuf[i].xfer, ISO_BUFFER_SIZE);
 		if(sc->sbuf[i].data == NULL) {
-			printf("%s: Failed to allocate transferbuffer\n",USBDEVNAME(sc->sc_dev));
+			device_printf(sc->sc_dev, "Failed to allocate transferbuffer\n");
 			goto bad;
 		}
 	}
@@ -466,8 +470,9 @@
 	   programs)
 	 */
 	if(sc->vframe_count > 20 && sc->stats) {
-		printf("%s: %d frames received, dumped %d frames, %d frames with errors.\n"
-			,USBDEVNAME(sc->sc_dev),sc->vframe_count, sc->vframes_dumped, sc->vframes_error);
+		device_printf(sc->sc_dev,
+            "%d frames received, dumped %d frames, %d frames with errors.\n",
+			sc->vframe_count, sc->vframes_dumped, sc->vframes_error);
 	}
 
 	if(sc->type == 645 || sc->type == 646)
@@ -491,7 +496,7 @@
 		
 		if(sc->power_save) {
 			if(pwc_camera_power(sc, 0) < 0)
-				printf("%s: Failed to power down the camera\n", USBDEVNAME(sc->sc_dev));
+				device_printf(sc->sc_dev, "Failed to power down the camera\n");
 		}
 	}
 	
@@ -662,13 +667,15 @@
 
 	err = usbd_set_interface(sc->sc_iface,sc->valternate);
 	if(err != USBD_NORMAL_COMPLETION) {
-		printf("%s: Failed to set alternate interface to: %d (%d)\n",USBDEVNAME(sc->sc_dev),sc->valternate,err);
+		device_printf(sc->sc_dev,
+            "Failed to set alternate interface to: %d (%d)\n",
+            sc->valternate,err);
 		return -err;
 	}
 
 	err = usbd_endpoint_count(sc->sc_iface, &nendpt);
         if(err != USBD_NORMAL_COMPLETION) {
-		printf("%s: Failed to get endpoint count (%d)\n",USBDEVNAME(sc->sc_dev),err);
+		device_printf(sc->sc_dev, "Failed to get endpoint count (%d)\n",err);
 		return -err;
 	}
 	for (i = 0; i < nendpt; i++) {
@@ -677,20 +684,20 @@
 			break;
 	}
 	if(i == nendpt) {
-		printf("%s: Failed to find videoendpoint\n",USBDEVNAME(sc->sc_dev));
+		device_printf(sc->sc_dev, "Failed to find videoendpoint\n");
 		return -EINVAL;
 	}
 	
 	sc->vmax_packet_size = UGETW(edesc->wMaxPacketSize);
 	if(sc->vmax_packet_size < 0 || sc->vmax_packet_size > ISO_MAX_FRAME_SIZE) {
-		printf("%s: Invalid packetsize (%d) for endpoint %d\n",USBDEVNAME(sc->sc_dev),
+		device_printf(sc->sc_dev, "Invalid packetsize (%d) for endpoint %d\n",
 			sc->vmax_packet_size,edesc->bEndpointAddress);
 		return -EINVAL;
 	}
 		 
 	err = usbd_open_pipe(sc->sc_iface,edesc->bEndpointAddress, 0, &sc->sc_videopipe);
 	if(err != USBD_NORMAL_COMPLETION) {
-		printf("%s: Failed to open videopipe (%d)\n",USBDEVNAME(sc->sc_dev),err);
+		device_printf(sc->sc_dev, "Failed to open videopipe (%d)\n", err);
 		return -err;
 	}
 
@@ -771,7 +778,8 @@
 		if (++sc->visoc_errors > MAX_ISOC_ERRORS) {
 			
 			if(sc->error_status != EIO)
-				printf("%s: Too many ISOC errors, bailing out.\n",USBDEVNAME(sc->sc_dev));
+				device_printf(sc->sc_dev, 
+                    "Too many ISOC errors, bailing out.\n");
 
 			sc->error_status = EIO;
 			awake = 1;
