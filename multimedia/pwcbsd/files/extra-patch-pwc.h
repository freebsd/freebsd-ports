--- pwc.h.orig	2006-09-27 07:21:01.000000000 +0200
+++ pwc.h	2009-09-09 10:16:04.000000000 +0200
@@ -44,8 +44,21 @@
 #include <vm/pmap.h>
 
 #include <dev/usb/usb.h>
-#include <dev/usb/usbdi.h>
-#include <dev/usb/usbdi_util.h>
+/* GJ
+#include <dev/usb/usb_mfunc.h>
+#include <dev/usb/usb_error.h>
+*/
+
+#include <dev/usb/usbdi.h> /* GJ */
+#include <dev/usb/usb_core.h>
+#include <dev/usb/usb_debug.h>
+/* GJ
+#include <dev/usb/usb_lookup.h>
+*/
+#include <dev/usb/usb_util.h>
+#include <dev/usb/usb_busdma.h>
+#include <dev/usb/usb_request.h>
+
 #include "pwc-uncompress.h"
 #include "pwc-ioctl.h"
 #include "videodev.h"
@@ -69,7 +82,7 @@
 #define TRACE_READ_VERBOSE 0x0800
 #define TRACE_SEQUENCE	0x1000
 
-#ifdef USB_DEBUG
+#if USB_DEBUG
 #define Trace(R, A...) if (pwcdebug & R) printf(PWC_NAME " " A)
 #define Debug(A...) if(pwcdebug) printf(PWC_NAME " " A)
 extern int  pwcdebug;
@@ -93,14 +106,9 @@
 #define FRAME_LOWMARK 5
 
 /* Size and number of buffers for the ISO pipe. */
-#define MAX_ISO_BUFS		3
-
-/* !!!!!!!!!! IMPORTANT DO NOT SET THIS HIGHER THAN 8 !!!!!!!!!!!!!!! 
- * !!!!!!!!!! OHCI IS BUGGY IF YOU DO SO              !!!!!!!!!!!!!!!*/
-#define ISO_FRAMES_PER_DESC	8
+#define MAX_ISO_BUFS		2
 
-#define ISO_MAX_FRAME_SIZE	960
-#define ISO_BUFFER_SIZE 	(ISO_FRAMES_PER_DESC * ISO_MAX_FRAME_SIZE)
+#define ISO_FRAMES_PER_DESC	16	/* should be multiple of 8 */
 
 /* Frame buffers: contains compressed or uncompressed video data. */
 #define MAX_FRAMES		5
@@ -133,17 +141,17 @@
 struct pwc_softc
 {
    device_t sc_dev;
-   usbd_device_handle udev;
-   usbd_interface_handle sc_iface;
-   usbd_pipe_handle sc_videopipe;
+
+   struct usb_xfer *sc_xfer[MAX_ISO_BUFS];
+   struct usb_device *udev;
    struct cdev *sc_dev_t;
    
    struct selinfo rsel;
-   char *name;
+   uint8_t sc_iface_index;
    int type;                    /* type of cam (645, 646, 675, 680, 690, 720, 730, 740, 750) */
    int release;			/* release number */
    int features;		/* feature bits */
-   char serial[USB_MAX_STRING_LEN]; /* serial number (string) */
+   char serial[64];		/* serial number (string) */
    int error_status;		/* set when something goes wrong with the cam (unplugged, USB errors) */
    int usb_init;		/* set when the cam has been initialized over USB */
 
@@ -165,7 +173,6 @@
    int vframe_count;		/* received frames */
    int vframes_dumped; 		/* counter for dumped frames */
    int vframes_error;		/* frames received in error */
-   int vmax_packet_size;	/* USB maxpacket size */
    u_int16_t vlast_packet_size;	/* for frame synchronisation */
    int visoc_errors;		/* number of contiguous ISOC errors */
    int vcompression;		/* desired compression factor */
@@ -187,15 +194,7 @@
       Note that MAX_ISO_BUFS != MAX_FRAMES != MAX_IMAGES....
       We have in effect a back-to-back-double-buffer system.
     */
-   /* 1: isoc */
-   struct pwc_iso_buf
-   {
-	unsigned char *data;
-	usbd_xfer_handle xfer;
- 	u_int16_t sizes[ISO_FRAMES_PER_DESC];
-	struct pwc_softc *sc;
-   } sbuf[MAX_ISO_BUFS];
- 
+
    char iso_init;
 
    /* 2: frame */
