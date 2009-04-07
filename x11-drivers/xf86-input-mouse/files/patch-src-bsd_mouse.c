--- src/bsd_mouse.c.orig	2008-11-26 23:11:36.000000000 -0500
+++ src/bsd_mouse.c	2009-04-07 17:10:17.000000000 -0400
@@ -1,4 +1,3 @@
-
 /*
  * Copyright (c) 1999-2003 by The XFree86 Project, Inc.
  *
@@ -71,15 +70,20 @@
 static const char *FindDevice(InputInfoPtr, const char *, int);
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if !defined(XPS2_SUPPORT) && (__FreeBSD_kernel_version >= 700106)
+#define XPS2_SUPPORT
+#endif
 /* These are for FreeBSD and DragonFly */
 #define DEFAULT_MOUSE_DEV		"/dev/mouse"
 #define DEFAULT_SYSMOUSE_DEV		"/dev/sysmouse"
 #define DEFAULT_PS2_DEV			"/dev/psm0"
+#define DEFAULT_USB_DEV			"/dev/ums0"
 
 static const char *mouseDevs[] = {
 	DEFAULT_MOUSE_DEV,
 	DEFAULT_SYSMOUSE_DEV,
 	DEFAULT_PS2_DEV,
+	DEFAULT_USB_DEV,
 	NULL
 };
 #elif (defined(__OpenBSD__) || defined(__NetBSD__)) && defined(WSCONS_SUPPORT)
@@ -100,7 +104,11 @@
 #if defined(__NetBSD__)
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO;
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-    return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO | MSE_MISC;
+    return MSE_SERIAL | MSE_BUS | MSE_PS2 |
+#ifdef XPS2_SUPPORT
+	MSE_XPS2 |
+#endif
+	MSE_AUTO | MSE_MISC;
 #else
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_XPS2 | MSE_AUTO;
 #endif
@@ -179,10 +187,31 @@
 	{ MOUSE_PROTO_THINK,		"ThinkingMouse" },
 	{ MOUSE_PROTO_SYSMOUSE,		"SysMouse" }
 };
-	
+
+#ifdef XPS2_SUPPORT
+static struct {
+	int dmodel;
+	char *name;
+} ps2proto[] = {
+	{ MOUSE_MODEL_NETSCROLL,	"NetScrollPS/2" },
+	{ MOUSE_MODEL_NET,		"NetMousePS/2" },
+	{ MOUSE_MODEL_GLIDEPOINT,	"GlidePointPS/2" },
+	{ MOUSE_MODEL_THINK,		"ThinkingMousePS/2" },
+	{ MOUSE_MODEL_INTELLI,		"IMPS/2" },
+	{ MOUSE_MODEL_MOUSEMANPLUS,	"MouseManPlusPS/2" },
+	{ MOUSE_MODEL_EXPLORER,		"ExplorerPS/2" },
+	{ MOUSE_MODEL_4D,		"IMPS/2" },
+	{ MOUSE_MODEL_4DPLUS,		"IMPS/2" },
+};
+#endif
+
 static const char *
 SetupAuto(InputInfoPtr pInfo, int *protoPara)
 {
+#ifdef XPS2_SUPPORT
+    char *dev;
+#endif
+    const char *proto;
     int i;
     mousehw_t hw;
     mousemode_t mode;
@@ -190,10 +219,16 @@
     if (pInfo->fd == -1)
 	return NULL;
 
+#ifdef XPS2_SUPPORT
     /* set the driver operation level, if applicable */
+    dev = xf86FindOptionValue(pInfo->options, "Device");
+    if (dev != NULL && !strncmp(dev, DEFAULT_PS2_DEV, 8))
+	i = 2;
+    else
+#endif
     i = 1;
     ioctl(pInfo->fd, MOUSE_SETLEVEL, &i);
-    
+
     /* interrogate the driver and get some intelligence on the device. */
     hw.iftype = MOUSE_IF_UNKNOWN;
     hw.model = MOUSE_MODEL_GENERIC;
@@ -209,9 +244,18 @@
 		    protoPara[0] = mode.syncmask[0];
 		    protoPara[1] = mode.syncmask[1];
 		}
+		proto = devproto[i].name;
+#ifdef XPS2_SUPPORT
+		if (mode.protocol == MOUSE_PROTO_PS2)
+		    for (i = 0; i < sizeof(ps2proto)/sizeof(ps2proto[0]); ++i)
+			if (hw.model == ps2proto[i].dmodel) {
+			    proto = ps2proto[i].name;
+			    break;
+			}
+#endif
 		xf86MsgVerb(X_INFO, 3, "%s: SetupAuto: protocol is %s\n",
-			    pInfo->name, devproto[i].name);
-		return devproto[i].name;
+			    pInfo->name, proto);
+		return proto;
 	    }
 	}
     }
@@ -234,41 +278,41 @@
 	(protocol && xf86NameCmp(protocol, "SysMouse") == 0)) {
 	/*
 	 * As the FreeBSD sysmouse driver defaults to protocol level 0
-	 * everytime it is opened we enforce protocol level 1 again at
+	 * everytime it is closed we enforce protocol level 1 again at
 	 * this point.
 	 */
 	mode.level = 1;
     } else
-	mode.level = -1;
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
-	if (fscanf(f, "%u", &pid) == 1 && pid > 0) {
-	    if (kill(pid, 0) == 0) {
-		fclose(f);
-		return TRUE;
-	    }
+    if (dev)
+	sprintf(cmd, "sh -c 'fstat %s | grep -c moused' 2>/dev/null", dev);
+    else
+	sprintf(cmd, "sh -c 'pgrep -nx moused' 2>/dev/null");
+    if ((f = popen(cmd, "r")) != NULL) {
+	if (fscanf(f, "%u", &i) == 1 && i > 0) {
+	    pclose(f);
+	    return TRUE;
 	}
-	fclose(f);
+	pclose(f);
     }
     return FALSE;
 }
@@ -276,17 +320,17 @@
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
-	SYSCALL (fd = open(*pdev, O_RDWR | O_NONBLOCK));
-	if (fd == -1) {
+	SYSCALL (ret = stat(*pdev, &sb));
+	if (ret == -1) {
 #ifdef DEBUG
-	    ErrorF("Cannot open %s (%s)\n", *pdev, strerror(errno));
+	    ErrorF("Cannot stat %s (%s)\n", *pdev, strerror(errno));
 #endif
 	} else {
 	    /*
@@ -295,28 +339,32 @@
 	     * the test for whether /dev/sysmouse is usable can be made.
 	     */
 	    if (!strcmp(*pdev, DEFAULT_MOUSE_DEV)) {
-		if (fstat(fd, &devMouseStat) == 0)
-		    devMouse = TRUE;
-		close(fd);
+		memcpy(&devMouseStat, &sb, sizeof(devMouseStat));
+		devMouse = TRUE;
 		continue;
 	    } else if (!strcmp(*pdev, DEFAULT_SYSMOUSE_DEV)) {
 		/* Check if /dev/mouse is the same as /dev/sysmouse. */
-		if (devMouse && fstat(fd, &sb) == 0 && 
-		    devMouseStat.st_dev == sb.st_dev &&
+		if (devMouse && devMouseStat.st_dev == sb.st_dev &&
 		    devMouseStat.st_ino == sb.st_ino) {
 		    /* If the same, use /dev/sysmouse. */
 		    devMouse = FALSE;
 		}
-		close(fd);
-		if (MousedRunning())
+		if (MousedRunning(NULL))
 		    break;
-		else {
-#ifdef DEBUG
-	    	    ErrorF("moused isn't running\n");
-#endif
-		}
 	    } else {
-		close(fd);
+		/* Check if /dev/mouse is the same as this device. */
+		if (devMouse && devMouseStat.st_dev == sb.st_dev &&
+		    devMouseStat.st_ino == sb.st_ino) {
+		    /* If the same, use this device. */
+		    devMouse = FALSE;
+		}
+		if (MousedRunning(*pdev))
+		    continue;
+		/* ums(4) does not support anything but SysMouse protocol. */
+		if (!strncmp(*pdev, DEFAULT_USB_DEV, 8) && protocol &&
+		    xf86NameCmp(protocol, "auto") != 0 &&
+		    xf86NameCmp(protocol, "sysmouse") != 0)
+		    continue;
 		break;
 	    }
 	}
@@ -782,7 +830,9 @@
     p->CheckProtocol = CheckProtocol;
 #if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)) && defined(MOUSE_PROTO_SYSMOUSE)
     p->SetupAuto = SetupAuto;
+#ifndef XPS2_SUPPORT
     p->SetPS2Res = SetSysMouseRes;
+#endif
     p->SetBMRes = SetSysMouseRes;
     p->SetMiscRes = SetSysMouseRes;
 #endif
