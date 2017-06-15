--- src/bsd_mouse.c.orig	2015-04-20 01:07:33 UTC
+++ src/bsd_mouse.c
@@ -26,6 +26,24 @@
  * authorization from the copyright holder(s) and author(s).
  */
 
+
+/*
+ * XXX - Should this be autoconf'd instead?
+ */
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+
+#if !defined(USBMOUSE_SUPPORT)
+#define USBMOUSE_SUPPORT
+#endif
+#if !defined(HAS_LIB_USB_HID)
+#define HAS_LIB_USB_HID
+#endif
+#if !defined(XPS2_SUPPORT)
+#define XPS2_SUPPORT
+#endif
+
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
+
 #include <xorg-server.h>
 
 #include <X11/X.h>
@@ -33,9 +51,23 @@
 #include "xf86Priv.h"
 #include "xf86_OSlib.h"
 #include "xf86Xinput.h"
+#include <exevents.h>
 #include "mouse.h"
 #include "xisb.h"
 #include "mipointer.h"
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 3
+#define HAVE_PROPERTIES 1
+#endif
+#ifdef HAVE_PROPERTIES
+#include <X11/Xatom.h>
+#include <xserver-properties.h>
+/* 1.6 has properties, but no labels */
+#ifdef AXIS_LABEL_PROP
+#define HAVE_LABELS
+#else
+#undef HAVE_LABELS
+#endif
+#endif
 #ifdef WSCONS_SUPPORT
 #include <dev/wscons/wsconsio.h>
 #endif
@@ -47,9 +79,6 @@
 #endif
 
 #include <dev/usb/usb.h>
-#ifdef USB_GET_REPORT_ID
-#define USB_NEW_HID
-#endif
 
 #define HUP_GENERIC_DESKTOP     0x0001
 #define HUP_BUTTON              0x0009
@@ -75,11 +104,13 @@ static const char *FindDevice(InputInfoP
 #define DEFAULT_MOUSE_DEV               "/dev/mouse"
 #define DEFAULT_SYSMOUSE_DEV            "/dev/sysmouse"
 #define DEFAULT_PS2_DEV                 "/dev/psm0"
+#define DEFAULT_USB_DEV                 "/dev/ums0"
 
 static const char *mouseDevs[] = {
         DEFAULT_MOUSE_DEV,
         DEFAULT_SYSMOUSE_DEV,
         DEFAULT_PS2_DEV,
+        DEFAULT_USB_DEV,
         NULL
 };
 #elif (defined(__OpenBSD__) || defined(__NetBSD__)) && defined(WSCONS_SUPPORT)
@@ -97,7 +128,7 @@ static const char *mouseDevs[] = {
 static int
 SupportedInterfaces(void)
 {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
+#if defined(__NetBSD__)
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO | MSE_MISC;
 #else
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_XPS2 | MSE_AUTO | MSE_MISC;
@@ -178,9 +209,30 @@ static struct {
         { MOUSE_PROTO_SYSMOUSE,         "SysMouse" }
 };
 
+#ifdef XPS2_SUPPORT
+static struct {
+        int dmodel;
+        const char *name;
+} ps2proto[] = {
+        { MOUSE_MODEL_NETSCROLL,        "NetScrollPS/2" },
+        { MOUSE_MODEL_NET,              "NetMousePS/2" },
+        { MOUSE_MODEL_GLIDEPOINT,       "GlidePointPS/2" },
+        { MOUSE_MODEL_THINK,            "ThinkingMousePS/2" },
+        { MOUSE_MODEL_INTELLI,          "IMPS/2" },
+        { MOUSE_MODEL_MOUSEMANPLUS,     "MouseManPlusPS/2" },
+        { MOUSE_MODEL_EXPLORER,         "ExplorerPS/2" },
+        { MOUSE_MODEL_4D,               "IMPS/2" },
+        { MOUSE_MODEL_4DPLUS,           "IMPS/2" },
+};
+#endif
+
 static const char *
 SetupAuto(InputInfoPtr pInfo, int *protoPara)
 {
+#ifdef XPS2_SUPPORT
+    const char *dev;
+#endif
+    const char *proto;
     int i;
     mousehw_t hw;
     mousemode_t mode;
@@ -188,7 +240,13 @@ SetupAuto(InputInfoPtr pInfo, int *proto
     if (pInfo->fd == -1)
         return NULL;
 
+#ifdef XPS2_SUPPORT
     /* set the driver operation level, if applicable */
+    dev = xf86FindOptionValue(pInfo->options, "Device");
+    if (dev != NULL && !strncmp(dev, DEFAULT_PS2_DEV, 8))
+        i = 2;
+    else
+#endif
     i = 1;
     ioctl(pInfo->fd, MOUSE_SETLEVEL, &i);
 
@@ -207,9 +265,18 @@ SetupAuto(InputInfoPtr pInfo, int *proto
                     protoPara[0] = mode.syncmask[0];
                     protoPara[1] = mode.syncmask[1];
                 }
+                proto = devproto[i].name;
+#ifdef XPS2_SUPPORT
+                if (mode.protocol == MOUSE_PROTO_PS2)
+                    for (i = 0; i < sizeof(ps2proto)/sizeof(ps2proto[0]); ++i)
+                        if (hw.model == ps2proto[i].dmodel) {
+                           proto = ps2proto[i].name;
+                           break;
+                }
+#endif
                 xf86MsgVerb(X_INFO, 3, "%s: SetupAuto: protocol is %s\n",
-                            pInfo->name, devproto[i].name);
-                return devproto[i].name;
+                            pInfo->name, proto);
+                return proto;
             }
         }
     }
@@ -232,41 +299,41 @@ SetSysMouseRes(InputInfoPtr pInfo, const
         (protocol && xf86NameCmp(protocol, "SysMouse") == 0)) {
         /*
          * As the FreeBSD sysmouse driver defaults to protocol level 0
-         * everytime it is opened we enforce protocol level 1 again at
+         * everytime it is closed we enforce protocol level 1 again at
          * this point.
          */
         mode.level = 1;
     } else
-        mode.level = -1;
-#else
-    mode.level = -1;
 #endif
+    mode.level = -1;
     ioctl(pInfo->fd, MOUSE_SETMODE, &mode);
 }
 #endif
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-
-#define MOUSED_PID_FILE "/var/run/moused.pid"
-
 /*
  * Try to check if moused is running.  DEFAULT_SYSMOUSE_DEV is useless without
- * it.  There doesn't seem to be a better way of checking.
+ * it.  Also, try to check if the device is used by moused.  If it is opened
+ * by moused, we do not want to use it directly.  There doesn't seem to be
+ * a better way of checking.
  */
 static Bool
-MousedRunning(void)
+MousedRunning(const char *dev)
 {
+    char cmd[128];
     FILE *f = NULL;
-    unsigned int pid;
+    unsigned int i;
 
-    if ((f = fopen(MOUSED_PID_FILE, "r")) != NULL) {
-        if (fscanf(f, "%u", &pid) == 1 && pid > 0) {
-            if (kill(pid, 0) == 0) {
-                fclose(f);
-                return TRUE;
-            }
+    if (dev)
+        sprintf(cmd, "sh -c 'fstat %s | grep -c moused' 2>/dev/null", dev);
+    else
+        sprintf(cmd, "sh -c 'pgrep -nx moused' 2>/dev/null");
+    if ((f = popen(cmd, "r")) != NULL) {
+        if (fscanf(f, "%u", &i) == 1 && i > 0) {
+            pclose(f);
+            return TRUE;
         }
-        fclose(f);
+        pclose(f);
     }
     return FALSE;
 }
@@ -274,17 +341,17 @@ MousedRunning(void)
 static const char *
 FindDevice(InputInfoPtr pInfo, const char *protocol, int flags)
 {
-    int fd = -1;
+    int ret = -1;
     const char **pdev, *dev = NULL;
     Bool devMouse = FALSE;
     struct stat devMouseStat;
     struct stat sb;
 
     for (pdev = mouseDevs; *pdev; pdev++) {
-        SYSCALL (fd = open(*pdev, O_RDWR | O_NONBLOCK));
-        if (fd == -1) {
+        SYSCALL (ret = stat(*pdev, &sb));
+        if (ret == -1) {
 #ifdef DEBUG
-            ErrorF("Cannot open %s (%s)\n", *pdev, strerror(errno));
+            ErrorF("Cannot stat %s (%s)\n", *pdev, strerror(errno));
 #endif
         } else {
             /*
@@ -293,28 +360,32 @@ FindDevice(InputInfoPtr pInfo, const cha
              * the test for whether /dev/sysmouse is usable can be made.
              */
             if (!strcmp(*pdev, DEFAULT_MOUSE_DEV)) {
-                if (fstat(fd, &devMouseStat) == 0)
-                    devMouse = TRUE;
-                close(fd);
+                memcpy(&devMouseStat, &sb, sizeof(devMouseStat));
+                devMouse = TRUE;
                 continue;
             } else if (!strcmp(*pdev, DEFAULT_SYSMOUSE_DEV)) {
                 /* Check if /dev/mouse is the same as /dev/sysmouse. */
-                if (devMouse && fstat(fd, &sb) == 0 &&
-                    devMouseStat.st_dev == sb.st_dev &&
+                if (devMouse && devMouseStat.st_dev == sb.st_dev &&
                     devMouseStat.st_ino == sb.st_ino) {
                     /* If the same, use /dev/sysmouse. */
                     devMouse = FALSE;
                 }
-                close(fd);
-                if (MousedRunning())
+                if (MousedRunning(NULL))
                     break;
-                else {
-#ifdef DEBUG
-                    ErrorF("moused isn't running\n");
-#endif
-                }
             } else {
-                close(fd);
+                /* Check if /dev/mouse is the same as this device. */
+                if (devMouse && devMouseStat.st_dev == sb.st_dev &&
+                    devMouseStat.st_ino == sb.st_ino) {
+                    /* If the same, use this device. */
+                    devMouse = FALSE;
+                }
+                if (MousedRunning(*pdev))
+                    continue;
+                /* ums(4) does not support anything but SysMouse protocol. */
+                if (!strncmp(*pdev, DEFAULT_USB_DEV, 8) && protocol &&
+                    xf86NameCmp(protocol, "auto") != 0 &&
+                    xf86NameCmp(protocol, "sysmouse") != 0)
+                    continue;
                 break;
             }
         }
@@ -486,30 +557,78 @@ wsconsPreInit(InputInfoPtr pInfo, const 
 
 #if defined(USBMOUSE_SUPPORT)
 
+#define MAXRIDS		64
+#define MAXACOLS	8
+#define MAXLCOLS	16
 typedef struct _UsbMseRec {
     int packetSize;
-    int iid;
-    hid_item_t loc_x;           /* x locator item */
-    hid_item_t loc_y;           /* y locator item */
-    hid_item_t loc_z;           /* z (wheel) locator item */
-    hid_item_t loc_w;           /* z (wheel) locator item */
-    hid_item_t loc_btn[MSE_MAXBUTTONS]; /* buttons locator items */
-   unsigned char *buffer;
+    int iid, nrids, nacols, opened;
+    struct {
+	int32_t rid;
+	int size;
+    } rids[MAXRIDS];
+    struct UsbMseAcol {
+	InputInfoPtr pInfo;
+	int nlcols, nbuttons, hasZ, hasW;
+	int xmin, xmax, ymin, ymax, pmin, pmax, px, py;
+	int cxmin, cxmax, cymin, cymax, cpmin, cpmax;
+	struct UsbMseLcol {
+	    hid_item_t loc_x;		/* x locator item */
+	    hid_item_t loc_y;		/* y locator item */
+	    hid_item_t loc_z;		/* z (wheel) locator item */
+	    hid_item_t loc_w;		/* w (hwheel) locator item */
+	    hid_item_t loc_p;		/* Tip Pressure */
+	    hid_item_t loc_valid;		/* Touch Valid */
+	    hid_item_t loc_in_range;	/* In Range */
+	    hid_item_t loc_btn[MSE_MAXBUTTONS]; /* buttons locator items */
+	} lcols[MAXLCOLS];
+	hid_item_t loc_cc;		/* contact count */
+    } acols[MAXACOLS];
+    unsigned char *buffer;
 } UsbMseRec, *UsbMsePtr;
 
+static int *
+usbGetReportSizePtr(UsbMsePtr pUsbMse, int32_t rid)
+{
+    int i;
+
+    for (i = 0; i < pUsbMse->nrids; i++) {
+	if (pUsbMse->rids[i].rid == rid)
+	    return (&pUsbMse->rids[i].size);
+    }
+    for (i = 0; i < MAXRIDS; i++) {
+	if (pUsbMse->rids[i].size == 0) {
+	    pUsbMse->rids[i].rid = rid;
+	    pUsbMse->nrids = max(pUsbMse->nrids, i + 1);
+	    return (&pUsbMse->rids[i].size);
+	}
+    }
+    return (NULL);
+}
+
 static int
 usbMouseProc(DeviceIntPtr pPointer, int what)
 {
     InputInfoPtr pInfo;
     MouseDevPtr pMse;
     UsbMsePtr pUsbMse;
+    struct UsbMseAcol *acol;
     unsigned char map[MSE_MAXBUTTONS + 1];
-    int nbuttons;
+    int nacol, nbuttons;
+#ifdef HAVE_LABELS
+    Atom btn_labels[MSE_MAXBUTTONS] = {0};
+    Atom axes_labels[3] = { 0, 0, 0 };
+#endif
 
     pInfo = pPointer->public.devicePrivate;
     pMse = pInfo->private;
     pMse->device = pPointer;
     pUsbMse = pMse->mousePriv;
+    for (nacol = 0; nacol < (pUsbMse->nacols - 1); nacol++) {
+	if (pUsbMse->acols[nacol].pInfo == pInfo)
+	    break;
+    }
+    acol = &pUsbMse->acols[nacol];
 
     switch (what) {
     case DEVICE_INIT:
@@ -518,38 +637,96 @@ usbMouseProc(DeviceIntPtr pPointer, int 
         for (nbuttons = 0; nbuttons < MSE_MAXBUTTONS; ++nbuttons)
             map[nbuttons + 1] = nbuttons + 1;
 
-        InitPointerDeviceStruct((DevicePtr)pPointer,
-                                map,
-                                min(pMse->buttons, MSE_MAXBUTTONS),
-                                miPointerGetMotionEvents,
-                                pMse->Ctrl,
-                                miPointerGetMotionBufferSize());
+#ifdef HAVE_LABELS
+	btn_labels[0] = XIGetKnownProperty(BTN_LABEL_PROP_BTN_LEFT);
+	btn_labels[1] = XIGetKnownProperty(BTN_LABEL_PROP_BTN_MIDDLE);
+	btn_labels[2] = XIGetKnownProperty(BTN_LABEL_PROP_BTN_RIGHT);
+	axes_labels[0] = XIGetKnownProperty((acol->xmin != acol->xmax)
+	    ? AXIS_LABEL_PROP_ABS_X : AXIS_LABEL_PROP_REL_X);
+	axes_labels[1] = XIGetKnownProperty((acol->xmin != acol->xmax)
+	    ? AXIS_LABEL_PROP_ABS_Y : AXIS_LABEL_PROP_REL_Y);
+	axes_labels[2] = XIGetKnownProperty(AXIS_LABEL_PROP_ABS_PRESSURE);
+#endif
+
+	InitButtonClassDeviceStruct(pPointer, min(pMse->buttons, MSE_MAXBUTTONS),
+#ifdef HAVE_LABELS
+	    btn_labels,
+#endif
+	    map);
+	InitValuatorClassDeviceStruct(pPointer, (acol->pmin != acol->pmax) ? 3 : 2,
+#ifdef HAVE_LABELS
+	    axes_labels,
+#endif
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) == 0
+	    miPointerGetMotionEvents,
+#elif GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 3
+	    GetMotionHistory,
+#endif
+	    GetMotionHistorySize(),
+	    (acol->xmin != acol->xmax || acol->ymin != acol->ymax) ?
+	     Absolute : Relative);
+	InitPtrFeedbackClassDeviceStruct(pPointer, pMse->Ctrl);
 
         /* X valuator */
-        xf86InitValuatorAxisStruct(pPointer, 0, 0, -1, 1, 0, 1);
+	xf86InitValuatorAxisStruct(pPointer, 0,
+#ifdef HAVE_LABELS
+	    axes_labels[0],
+#endif
+	    (acol->xmin != acol->xmax) ? acol->xmin : -1,
+	    (acol->xmin != acol->xmax) ? acol->xmax : -1,
+	    1, 0, 1
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 12
+	    , (acol->xmin != acol->xmax) ? Absolute : Relative
+#endif
+	    );
         xf86InitValuatorDefaults(pPointer, 0);
         /* Y valuator */
-        xf86InitValuatorAxisStruct(pPointer, 1, 0, -1, 1, 0, 1);
+	xf86InitValuatorAxisStruct(pPointer, 1,
+#ifdef HAVE_LABELS
+	    axes_labels[1],
+#endif
+	    (acol->ymin != acol->ymax) ? acol->ymin : -1,
+	    (acol->ymin != acol->ymax) ? acol->ymax : -1,
+	    1, 0, 1
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 12
+	    , (acol->ymin != acol->ymax) ? Absolute : Relative
+#endif
+	    );
         xf86InitValuatorDefaults(pPointer, 1);
+	/* Pressure valuator */
+	if (acol->pmin != acol->pmax) {
+	    xf86InitValuatorAxisStruct(pPointer, 2,
+#ifdef HAVE_LABELS
+		axes_labels[2],
+#endif
+		acol->pmin, acol->pmax, 1, 0, 1
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 12
+		, Absolute
+#endif
+		);
+	    xf86InitValuatorDefaults(pPointer, 2);
+	}
         xf86MotionHistoryAllocate(pInfo);
         break;
 
     case DEVICE_ON:
-        pInfo->fd = xf86OpenSerial(pInfo->options);
-        if (pInfo->fd == -1)
-            xf86Msg(X_WARNING, "%s: cannot open input device\n", pInfo->name);
-        else {
-            pMse->buffer = XisbNew(pInfo->fd, pUsbMse->packetSize);
-            if (!pMse->buffer) {
-                free(pMse);
-                xf86CloseSerial(pInfo->fd);
-                pInfo->fd = -1;
-            } else {
-                xf86FlushInput(pInfo->fd);
-                if (!xf86InstallSIGIOHandler (pInfo->fd, usbSigioReadInput,
-                                              pInfo))
-                    AddEnabledDevice(pInfo->fd);
-            }
+	if (pUsbMse->opened++ == 0) {
+		pInfo->fd = xf86OpenSerial(pInfo->options);
+		if (pInfo->fd == -1)
+		    xf86Msg(X_WARNING, "%s: cannot open input device\n", pInfo->name);
+		else {
+		    pMse->buffer = XisbNew(pInfo->fd, pUsbMse->packetSize);
+		    if (!pMse->buffer) {
+			free(pMse);
+			xf86CloseSerial(pInfo->fd);
+			pInfo->fd = -1;
+		    } else {
+			xf86FlushInput(pInfo->fd);
+			if (!xf86InstallSIGIOHandler (pInfo->fd, usbSigioReadInput, 
+						      pInfo))
+			    xf86AddEnabledDevice(pInfo);
+		    }
+		}
         }
         pMse->lastButtons = 0;
         pMse->lastMappedButtons = 0;
@@ -560,7 +737,7 @@ usbMouseProc(DeviceIntPtr pPointer, int 
     case DEVICE_OFF:
     case DEVICE_CLOSE:
         if (pInfo->fd != -1) {
-            RemoveEnabledDevice(pInfo->fd);
+            xf86RemoveEnabledDevice(pInfo);
             if (pUsbMse->packetSize > 8 && pUsbMse->buffer) {
                 free(pUsbMse->buffer);
             }
@@ -571,6 +748,7 @@ usbMouseProc(DeviceIntPtr pPointer, int 
             xf86CloseSerial(pInfo->fd);
             pInfo->fd = -1;
         }
+        pUsbMse->opened--;
         pPointer->public.on = FALSE;
         usleep(300000);
         break;
@@ -586,45 +764,154 @@ usbReadInput(InputInfoPtr pInfo)
 {
     MouseDevPtr pMse;
     UsbMsePtr pUsbMse;
-    int buttons = pMse->lastButtons;
-    int dx = 0, dy = 0, dz = 0, dw = 0;
-    int n, c;
+    int buttons, cc;
+    int dx, dy, dz, dw, dp, upd, v, nx, ny, np, in_range;
+    int n, c, rid, *sizep, nacol, nlcol;
     unsigned char *pBuf;
+    struct UsbMseAcol *acol;
+    struct UsbMseLcol *lcol;
 
     pMse = pInfo->private;
     pUsbMse = pMse->mousePriv;
 
     XisbBlockDuration(pMse->buffer, -1);
+next:
     pBuf = pUsbMse->buffer;
     n = 0;
-    while ((c = XisbRead(pMse->buffer)) >= 0 && n < pUsbMse->packetSize) {
+    if (pUsbMse->iid) {
+	rid = XisbRead(pMse->buffer);
+	if (rid < 0)
+	    return;
+	pBuf[n++] = (unsigned char)rid;
+    } else
+	rid = 0;
+    sizep = usbGetReportSizePtr(pUsbMse, rid);
+    if (sizep == NULL || *sizep == 0) {
+	xf86Msg(X_WARNING, "%s: unknown report ID %d\n", pInfo->name, rid);
+	goto next;
+    }
+    while (n < *sizep && (c = XisbRead(pMse->buffer)) >= 0) {
         pBuf[n++] = (unsigned char)c;
     }
     if (n == 0)
         return;
-    if (n != pUsbMse->packetSize) {
+//    xf86MsgVerb(X_INFO, 3, "pkt: %d %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
+//	n, pBuf[0], pBuf[1], pBuf[2], pBuf[3], pBuf[4], pBuf[5], pBuf[6], pBuf[7], pBuf[8], pBuf[9]);
+    if (n != *sizep) {
         LogMessageVerbSigSafe(X_WARNING, -1,
                               "%s: incomplete packet, size %d\n",
                               pInfo->name, n);
     }
-    /* discard packets with an id that don't match the mouse */
-    /* XXX this is probably not the right thing */
-    if (pUsbMse->iid != 0) {
-        if (*pBuf++ != pUsbMse->iid)
-            return;
-    }
-    dx = hid_get_data(pBuf, &pUsbMse->loc_x);
-    dy = hid_get_data(pBuf, &pUsbMse->loc_y);
-    dz = hid_get_data(pBuf, &pUsbMse->loc_z);
-    dw = hid_get_data(pBuf, &pUsbMse->loc_w);
+    for (nacol = 0; nacol < pUsbMse->nacols; nacol++) {
+	acol = &pUsbMse->acols[nacol];
+	if (acol->pInfo == NULL)
+	    continue;
+	nx = ny = np = upd = 0;
+	buttons = cc = 0;
+	dx = dy = dz = dw = dp = 0;
+	for (nlcol = 0; nlcol < pUsbMse->acols[nacol].nlcols; nlcol++) {
+	    lcol = &acol->lcols[nlcol];
 
-    buttons = 0;
-    for (n = 0; n < pMse->buttons; n++) {
-        if (hid_get_data(pBuf, &pUsbMse->loc_btn[n]))
-            buttons |= (1 << UMS_BUT(n));
+	    if (lcol->loc_valid.usage != 0 && rid == lcol->loc_valid.report_ID &&
+		    hid_get_data(pBuf, &lcol->loc_valid) == 0)
+		continue;
+	    if (lcol->loc_in_range.usage != 0 && rid == lcol->loc_in_range.report_ID)
+		in_range = hid_get_data(pBuf, &lcol->loc_in_range);
+	    else
+		in_range = 1;
+	    if (in_range && lcol->loc_x.usage != 0 && rid == lcol->loc_x.report_ID && nx == 0) {
+		v = hid_get_data(pBuf, &lcol->loc_x);
+		if (acol->xmin != acol->xmax) {
+		    v = xf86ScaleAxis(v, acol->xmax, acol->xmin,
+			lcol->loc_x.logical_maximum, lcol->loc_x.logical_minimum);
+		    if (acol->cxmin != acol->cxmax)
+		        v = xf86ScaleAxis(v, acol->xmax, acol->xmin,
+			    acol->cxmax, acol->cxmin);
+		}
+		dx += v;
+		nx++;
+	    }
+	    if (in_range && lcol->loc_y.usage != 0 && rid == lcol->loc_y.report_ID && ny == 0) {
+		v = hid_get_data(pBuf, &lcol->loc_y);
+		if (acol->xmin != acol->xmax) {
+		    v = xf86ScaleAxis(v, acol->ymax, acol->ymin,
+			lcol->loc_y.logical_maximum, lcol->loc_y.logical_minimum);
+		    if (acol->cymin != acol->cymax)
+		        v = xf86ScaleAxis(v, acol->ymax, acol->ymin,
+			    acol->cymax, acol->cymin);
+		}
+		dy += v;
+		ny++;
+	    }
+	    if (lcol->loc_z.usage != 0 && rid == lcol->loc_z.report_ID) {
+		dz -= hid_get_data(pBuf, &lcol->loc_z);
+		upd = 1;
+	    }
+	    if (lcol->loc_w.usage != 0 && rid == lcol->loc_w.report_ID) {
+		dw += hid_get_data(pBuf, &lcol->loc_w);
+		upd = 1;
+	    }
+	    if (lcol->loc_p.usage != 0 && rid == lcol->loc_p.report_ID && np == 0) {
+		v = hid_get_data(pBuf, &lcol->loc_p);
+		    v = xf86ScaleAxis(v, acol->pmax, acol->pmin,
+			lcol->loc_p.logical_maximum, lcol->loc_p.logical_minimum);
+		    if (acol->cpmin != acol->cpmax)
+		        v = xf86ScaleAxis(v, acol->pmax, acol->pmin,
+			    acol->cpmax, acol->cpmin);
+		dp += v;
+		np++;
+	    }
+
+	    for (n = 0; n < acol->nbuttons; n++) {
+		if (lcol->loc_btn[n].usage != 0 && rid == lcol->loc_btn[n].report_ID) {
+		    if (hid_get_data(pBuf, &lcol->loc_btn[n]))
+			buttons |= (1 << UMS_BUT(n));
+		    upd = 1;
+		}
+	    }
+	}
+	if (acol->loc_cc.usage != 0 && rid == acol->loc_cc.report_ID)
+	    cc = hid_get_data(pBuf, &acol->loc_cc);
+	else
+	    cc = (nx || ny) ? 1 : 0;
+	if (cc > 1)
+	    buttons = (1 << UMS_BUT(1));
+	if (nx != 0 && acol->xmin != acol->xmax)
+	    dx /= nx;
+	if (ny != 0 && acol->ymin != acol->ymax)
+	    dy /= ny;
+	if (np != 0 && acol->pmin != acol->pmax)
+	    dp /= np;
+//	if (upd || nx || ny || np)
+//	    xf86MsgVerb(X_INFO, 3, "%d cc %d dx %d dy %d dz %d dw %d press %d buttons %02x\n",
+//		nacol, cc, dx, dy, dz, dw, dp, buttons);
+	if (nx != 0 || ny != 0) {
+	    if (acol->pmin != acol->pmax) {
+		xf86PostMotionEvent(acol->pInfo->dev,
+			    /* is_absolute: */    TRUE,
+			    /* first_valuator: */ 0,
+			    /* num_valuators: */  3,
+			    dx, dy, dp);
+	    } else if (acol->xmin != acol->xmax || acol->ymin != acol->ymax) {
+		xf86PostMotionEvent(acol->pInfo->dev,
+			    /* is_absolute: */    TRUE,
+			    /* first_valuator: */ 0,
+			    /* num_valuators: */  2,
+			    dx, dy);
+	    }
+	}
+	if (upd || (nx != 0) || (ny != 0)) {
+	    ((MouseDevPtr)acol->pInfo->private)->PostEvent(acol->pInfo, buttons,
+		((acol->xmin != acol->xmax) ? dx - acol->px : dx),
+		((acol->ymin != acol->ymax) ? dy - acol->py : dy),
+		dz, dw);
+	}
+	if (nx > 0)
+	    acol->px = dx;
+	if (ny > 0)
+	    acol->py = dy;
     }
-    pMse->PostEvent(pInfo, buttons, dx, dy, dz, dw);
-    return;
+    goto next;
 }
 
 static void
@@ -633,14 +920,17 @@ usbSigioReadInput (int fd, void *closure
     usbReadInput ((InputInfoPtr) closure);
 }
 
-/* This function is called when the protocol is "usb". */
 static Bool
-usbPreInit(InputInfoPtr pInfo, const char *protocol, int flags)
+usbInitFirst(InputInfoPtr pInfo)
 {
     MouseDevPtr pMse = pInfo->private;
     UsbMsePtr pUsbMse;
     report_desc_t reportDesc;
-    int i;
+    hid_data_t d;
+    hid_item_t h;
+    struct UsbMseAcol *acol;
+    struct UsbMseLcol *lcol;
+    int mdepth, rsize, *rsizep, acolused, lcolused, used;
 
     pUsbMse = malloc(sizeof(UsbMseRec));
     if (pUsbMse == NULL) {
@@ -649,12 +939,7 @@ usbPreInit(InputInfoPtr pInfo, const cha
         return FALSE;
     }
 
-    pMse->protocol = protocol;
-    xf86Msg(X_CONFIG, "%s: Protocol: %s\n", pInfo->name, protocol);
-
-    /* Collect the options, and process the common options. */
-    COLLECT_INPUT_OPTIONS(pInfo, NULL);
-    xf86ProcessCommonOptions(pInfo, pInfo->options);
+    bzero(pUsbMse, sizeof(UsbMseRec));
 
     /* Check if the device can be opened. */
     pInfo->fd = xf86OpenSerial(pInfo->options);
@@ -670,19 +955,134 @@ usbPreInit(InputInfoPtr pInfo, const cha
     }
     /* Get USB informations */
     reportDesc = hid_get_report_desc(pInfo->fd);
-    /* Get packet size & iid */
-#ifdef USB_NEW_HID
-    if (ioctl(pInfo->fd, USB_GET_REPORT_ID, &pUsbMse->iid) == -1) {
-            xf86Msg(X_ERROR, "Error ioctl USB_GET_REPORT_ID on %s : %s\n",
-                    pInfo->name, strerror(errno));
-            return FALSE;
+    mdepth = 0;
+    pUsbMse->nacols = 0;
+    acol = &pUsbMse->acols[pUsbMse->nacols];
+    lcol = &acol->lcols[acol->nlcols];
+    acolused = 0;
+    lcolused = 0;
+    d = hid_start_parse(reportDesc, (1 << hid_input) |
+	(1 << hid_collection) | (1 << hid_endcollection), -1);
+    while (hid_get_item(d, &h)) {
+	switch (h.kind) {
+	case hid_collection:
+	    if (mdepth != 0)
+		mdepth++;
+	    else if (h.collection == 1 &&
+		    (h.usage == 0x00010001 || h.usage == 0x00010002 ||
+		     (h.usage >= 0x000d0001 && h.usage <= 0x000d000d))) {
+		mdepth++;
+		if (acolused) {
+		    if (lcolused) {
+			acol->nlcols++;
+			lcolused = 0;
+		    }
+		    pUsbMse->nacols++;
+		    acolused = 0;
+		    acol = &pUsbMse->acols[pUsbMse->nacols];
+		    lcol = &acol->lcols[acol->nlcols];
+		}
+	    }
+	    if (lcolused && (h.collection == 0 ||
+		    h.collection == 2 || h.collection == 3)) {
+		acol->nlcols++;
+		lcolused = 0;
+		lcol = &acol->lcols[acol->nlcols];
+	    }
+	    break;
+	case hid_endcollection:
+	    if (mdepth != 0)
+		mdepth--;
+	    break;
+	case hid_input:
+	    if (h.report_ID != 0)
+		pUsbMse->iid = 1;
+	    rsize = pUsbMse->iid +
+		(h.pos + (h.report_size * h.report_count) + 7) / 8;
+	    if ((rsizep = usbGetReportSizePtr(pUsbMse, h.report_ID)) != NULL)
+		*rsizep = max(*rsizep, rsize);
+	    pUsbMse->packetSize = max(pUsbMse->packetSize, rsize);
+	    if (mdepth == 0)
+		break;
+	    used = 1;
+	    if (h.usage == 0x00010030) { /* X */
+		lcol->loc_x = h;
+		if ((h.flags & 0x04) == 0) {
+		    if (acol->xmin == acol->xmax) {
+			acol->xmin = h.logical_minimum;
+			acol->xmax = h.logical_maximum;
+		    } else {
+			acol->xmin = min(acol->xmin, h.logical_minimum);
+			acol->xmax = max(acol->xmax, h.logical_maximum);
+		    }
+		}
+	    } else if (h.usage == 0x00010031) { /* Y */
+		lcol->loc_y = h;
+		if ((h.flags & 0x04) == 0) {
+		    if (acol->ymin == acol->ymax) {
+			acol->ymin = h.logical_minimum;
+			acol->ymax = h.logical_maximum;
+		    } else {
+			acol->ymin = min(acol->ymin, h.logical_minimum);
+			acol->ymax = max(acol->ymax, h.logical_maximum);
+		    }
+		}
+	    } else if (h.usage == 0x00010038) { /* Z */
+		lcol->loc_z = h;
+		acol->hasZ = 1;
+	    } else if (h.usage == 0x000c0238) { /* W */
+		lcol->loc_w = h;
+		acol->hasW = 1;
+	    } else if (h.usage == 0x000d0030) { /* Press */
+		lcol->loc_p = h;
+		if ((h.flags & 0x04) == 0) {
+		    if (acol->pmin == acol->pmax) {
+			acol->pmin = h.logical_minimum;
+			acol->pmax = h.logical_maximum;
+		    } else {
+			acol->pmin = min(acol->pmin, h.logical_minimum);
+			acol->pmax = max(acol->pmax, h.logical_maximum);
+		    }
+		}
+	    } else if (h.usage == 0x000d0032) /* In Range */
+		lcol->loc_in_range = h;
+	    else if (h.usage == 0x000d0047) /* Valid */
+		lcol->loc_valid = h;
+	    else if (h.usage > 0x00090000 &&
+		h.usage <= 0x00090000 + MSE_MAXBUTTONS) { /* Buttons */
+		    lcol->loc_btn[(h.usage & 0xffff) - 1] = h;
+		    acol->nbuttons = max(acol->nbuttons, h.usage & 0xffff);
+	    } else if (h.usage == 0x000d0042) { /* Tip Switch */
+		lcol->loc_btn[0] = h;
+		acol->nbuttons = max(acol->nbuttons, 1);
+	    } else if (h.usage == 0x000d0044) { /* Barrel Switch */
+		lcol->loc_btn[1] = h;
+		acol->nbuttons = max(acol->nbuttons, 2);
+	    } else if (h.usage == 0x000d0045) { /* Eraser */
+		lcol->loc_btn[3] = h;
+		acol->nbuttons = max(acol->nbuttons, 4);
+	    } else if (h.usage == 0x000d0046) { /* Tablet Pick */
+		lcol->loc_btn[2] = h;
+		acol->nbuttons = max(acol->nbuttons, 3);
+	    } else if (h.usage == 0x000d0054) /* Contact Count */
+		acol->loc_cc = h;
+	    else
+		used = 0;
+	    lcolused += used;
+	    acolused += used;
+	    break;
+	default:
+	    break;
+	}
     }
-    pUsbMse->packetSize = hid_report_size(reportDesc, hid_input,
-                                              pUsbMse->iid);
-#else
-    pUsbMse->packetSize = hid_report_size(reportDesc, hid_input,
-                                              &pUsbMse->iid);
-#endif
+    if (lcolused)
+	acol->nlcols++;
+    if (acolused)
+	pUsbMse->nacols++;
+    hid_end_parse(d);
+    xf86Msg(X_DEFAULT, "%s: Found %d usable logical collections\n",
+	pInfo->name, pUsbMse->nacols);
+
     /* Allocate buffer */
     if (pUsbMse->packetSize <= 8) {
         pUsbMse->buffer = pMse->protoBuf;
@@ -692,56 +1092,129 @@ usbPreInit(InputInfoPtr pInfo, const cha
     if (pUsbMse->buffer == NULL) {
         xf86Msg(X_ERROR, "%s: cannot allocate buffer\n", pInfo->name);
         free(pUsbMse);
-        free(pMse);
         xf86CloseSerial(pInfo->fd);
         return FALSE;
     }
-#ifdef USB_NEW_HID
-    if (hid_locate(reportDesc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_X),
-                   hid_input, &pUsbMse->loc_x, pUsbMse->iid) < 0) {
-        xf86Msg(X_WARNING, "%s: no x locator\n", pInfo->name);
-    }
-    if (hid_locate(reportDesc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_Y),
-                   hid_input, &pUsbMse->loc_y, pUsbMse->iid) < 0) {
-        xf86Msg(X_WARNING, "%s: no y locator\n", pInfo->name);
-    }
-    if (hid_locate(reportDesc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_WHEEL),
-                   hid_input, &pUsbMse->loc_z, pUsbMse->iid) < 0) {
-    }
-#else
-    if (hid_locate(reportDesc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_X),
-                   hid_input, &pUsbMse->loc_x) < 0) {
-        xf86Msg(X_WARNING, "%s: no x locator\n", pInfo->name);
-    }
-    if (hid_locate(reportDesc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_Y),
-                   hid_input, &pUsbMse->loc_y) < 0) {
-        xf86Msg(X_WARNING, "%s: no y locator\n", pInfo->name);
-    }
-    if (hid_locate(reportDesc, HID_USAGE2(HUP_GENERIC_DESKTOP, HUG_WHEEL),
-                   hid_input, &pUsbMse->loc_z) < 0) {
-    }
-#endif
-    /* Probe for number of buttons */
-    for (i = 1; i <= MSE_MAXBUTTONS; i++) {
-        if (!hid_locate(reportDesc, HID_USAGE2(HUP_BUTTON, i),
-                        hid_input, &pUsbMse->loc_btn[i-1]
-#ifdef USB_NEW_HID
-                        , pUsbMse->iid
-#endif
-                        ))
-            break;
-    }
-    pMse->buttons = i-1;
 
     xf86CloseSerial(pInfo->fd);
     pInfo->fd = -1;
 
     /* Private structure */
     pMse->mousePriv = pUsbMse;
+    return TRUE;
+}
+
+/* This function is called when the protocol is "usb". */
+static Bool
+usbPreInit(InputInfoPtr pInfo, const char *protocol, int flags)
+{
+    InputInfoPtr pMatch;
+    MouseDevPtr pMse = pInfo->private;
+    UsbMsePtr pUsbMse;
+    struct UsbMseAcol *acol;
+    char *str;
+    int i, colopt;
+
+    pMse->protocol = protocol;
+    xf86Msg(X_CONFIG, "%s: Protocol: %s\n", pInfo->name, protocol);
+
+    /* Collect the options, and process the common options. */
+    COLLECT_INPUT_OPTIONS(pInfo, NULL);
+    xf86ProcessCommonOptions(pInfo, pInfo->options);
+
+    /* Check if this HID device is already opened. */
+    for (pMatch = xf86FirstLocalDevice(); pMatch != NULL; pMatch = pMatch->next) {
+	if ((pInfo != pMatch) && strstr(pMatch->drv->driverName, "mouse")) {
+	    char *dev1, *dev2;
+
+	    dev1 = xf86SetStrOption(pInfo->options, "Device", NULL);
+	    dev2 = xf86SetStrOption(pMatch->options, "Device", NULL);
+	    if (strcmp(dev1, dev2) == 0) {
+		free(dev1);
+		free(dev2);
+		break;
+	    }
+	    free(dev1);
+	    free(dev2);
+	}
+    }
+    if (pMatch == NULL) {
+	xf86Msg(X_DEFAULT, "%s: Opening new HID device\n", pInfo->name);
+	if (!usbInitFirst(pInfo)) {
+	    free(pMse);
+	    return FALSE;
+	}
+    } else {
+	pMse->mousePriv = ((MouseDevPtr)pMatch->private)->mousePriv;
+	xf86Msg(X_DEFAULT, "%s: Attaching to already opened HID device\n",
+	    pInfo->name);
+    }
+    pUsbMse = pMse->mousePriv;
+
+    /* Attach to collection, respecting "Collection" option. */
+    colopt = xf86SetIntOption(pInfo->options, "Collection", 0);
+    for (i = 0; i < pUsbMse->nacols; i++) {
+	if (pUsbMse->acols[i].pInfo == NULL &&
+		(colopt == 0 || i == colopt - 1)) {
+	    pUsbMse->acols[i].pInfo = pInfo;
+	    break;
+	}
+    }
+    xf86Msg(colopt == 0 ? X_DEFAULT : X_CONFIG,
+	"%s: Collection: %d\n", pInfo->name,
+	i == pUsbMse->nacols ? colopt : i + 1);
+    if (i == pUsbMse->nacols) {
+	xf86Msg(X_ERROR,
+	    "%s: Application collection not found or already handled\n",
+	    pInfo->name);
+	free(pMse);
+	return FALSE;
+    }
+
+    acol = &pUsbMse->acols[i];
+    pMse->buttons = acol->nbuttons;
+    if (pMse->buttons == 2)
+	pMse->buttons = 3;
+    if (acol->xmin != acol->xmax || acol->ymin != acol->ymax)
+	pMse->disableXY = TRUE;
+    pMse->hasZ = acol->hasZ;
+    pMse->hasW = acol->hasW;
 
     /* Process common mouse options (like Emulate3Buttons, etc). */
     pMse->CommonOptions(pInfo);
 
+    /* Process "Calibration" option. */
+    str = xf86CheckStrOption(pInfo->options, "Calibration", NULL);
+    if (str != NULL && (acol->xmin != acol->xmax || acol->ymin != acol->ymax)) {
+	int j, xmin, xmax, ymin, ymax, pmin, pmax;
+
+	j = sscanf(str, "%d %d %d %d %d %d", &xmin, &xmax, &ymin, &ymax, &pmin, &pmax);
+	if (j == 4) {
+	    xf86Msg(X_CONFIG, "%s: Calibration: %d %d %d %d\n",
+		pInfo->name, xmin, xmax, ymin, ymax);
+	    acol->cxmin = xmin;
+	    acol->cxmax = xmax;
+	    acol->cymin = ymin;
+	    acol->cymax = ymax;
+	} else if (j == 6) {
+	    xf86Msg(X_CONFIG, "%s: Calibration: %d %d %d %d %d %d\n",
+		pInfo->name, xmin, xmax, ymin, ymax, pmin, pmax);
+	    acol->cxmin = xmin;
+	    acol->cxmax = xmax;
+	    acol->cymin = ymin;
+	    acol->cymax = ymax;
+	    acol->cpmin = pmin;
+	    acol->cpmax = pmax;
+	} else
+	    xf86Msg(X_WARNING, "%s: Calibration: Invalid arguments\n",
+		pInfo->name);
+	free(str);
+    } else if (acol->xmin != acol->xmax || acol->ymin != acol->ymax) {
+	xf86Msg(X_DEFAULT, "%s: Calibration: %d %d %d %d %d %d\n",
+	    pInfo->name, acol->xmin, acol->xmax, acol->ymin, acol->ymax,
+	    acol->pmin, acol->pmax);
+    }
+
     /* Setup the local procs. */
     pInfo->device_control = usbMouseProc;
     pInfo->read_input = usbReadInput;
@@ -784,7 +1257,9 @@ OSMouseInit(int flags)
     p->CheckProtocol = CheckProtocol;
 #if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)) && defined(MOUSE_PROTO_SYSMOUSE)
     p->SetupAuto = SetupAuto;
+#ifndef XPS2_SUPPORT
     p->SetPS2Res = SetSysMouseRes;
+#endif
     p->SetBMRes = SetSysMouseRes;
     p->SetMiscRes = SetSysMouseRes;
 #endif
