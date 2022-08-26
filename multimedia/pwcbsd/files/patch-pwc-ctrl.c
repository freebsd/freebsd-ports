--- pwc-ctrl.c.orig	2007-07-02 06:54:19 UTC
+++ pwc-ctrl.c
@@ -130,7 +130,7 @@ static void pwc_set_image_buffer_size(struct pwc_softc
 static void pwc_set_image_buffer_size(struct pwc_softc *pdev);
 
 /****************************************************************************/
-static int usb_control_msg(usbd_device_handle udev,u_int pipe,u_int8_t request,u_int8_t requesttype,
+static int usb_control_msg(struct usb_device *udev,u_int pipe,u_int8_t request,u_int8_t requesttype,
 			   u_int16_t value, u_int16_t index, void *data, u_int16_t size,int timeout)
 {
 	usb_device_request_t req;
@@ -139,10 +139,10 @@ static int usb_control_msg(usbd_device_handle udev,u_i
 	USETW(req.wValue, value);
 	USETW(req.wIndex, index);
 	USETW(req.wLength,size);
-	return  -usbd_do_request(udev, &req, data);
+	return  -usbd_do_request(udev, NULL, &req, data);
 }
-      
 
+
 #define SendControlMsg(request, value, buflen) \
 	usb_control_msg(pdev->udev, 0, \
 		request, \
@@ -159,7 +159,7 @@ static int usb_control_msg(usbd_device_handle udev,u_i
 		pdev->vcinterface, \
 		&buf, buflen, 500)
 
-static int send_video_command(usbd_device_handle udev, int index, void *buf, int buflen)
+static int send_video_command(struct usb_device *udev, int index, void *buf, int buflen)
 {
 	return usb_control_msg(udev,
 		0,
@@ -1150,7 +1150,7 @@ int pwc_mpt_set_angle(struct pwc_softc *pdev, int pan,
 		pdev->pan_angle  += pan;
 		pdev->tilt_angle += tilt;
 	}
-	if (ret == -USBD_STALLED) /* stall -> out of range */
+	if (ret == -USB_ERR_STALLED) /* stall -> out of range */
 		ret = -ERANGE;				
 	return ret;
 }
@@ -1284,7 +1284,7 @@ int pwc_do_ioctl(struct pwc_softc *pdev, unsigned int 
 	{
 		ARG_DEF(struct pwc_probe, probe)
 		
-		strncpy(ARGR(probe).name, pdev->name,sizeof(ARGR(probe).name) - 1);
+		strncpy(ARGR(probe).name,device_get_desc(pdev->sc_dev),sizeof(ARGR(probe).name) - 1);
 		ARGR(probe).name[sizeof(ARGR(probe).name) - 1] = '\0';
 		ARGR(probe).type = pdev->type;
 		ARG_OUT(probe)
