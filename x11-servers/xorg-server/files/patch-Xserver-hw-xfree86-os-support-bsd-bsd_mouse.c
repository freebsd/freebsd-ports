--- hw/xfree86/os-support/bsd/bsd_mouse.c.orig	2007-08-23 15:05:48.000000000 -0400
+++ hw/xfree86/os-support/bsd/bsd_mouse.c	2008-04-08 15:41:42.000000000 -0400
@@ -1,4 +1,3 @@
-
 /*
  * Copyright (c) 1999-2003 by The XFree86 Project, Inc.
  *
@@ -76,11 +75,15 @@
 #define DEFAULT_MOUSE_DEV		"/dev/mouse"
 #define DEFAULT_SYSMOUSE_DEV		"/dev/sysmouse"
 #define DEFAULT_PS2_DEV			"/dev/psm0"
+#define DEFAULT_USB_DEV			"/dev/ums0"
 
 static const char *mouseDevs[] = {
 	DEFAULT_MOUSE_DEV,
 	DEFAULT_SYSMOUSE_DEV,
+#ifndef CONFIG_HAL
 	DEFAULT_PS2_DEV,
+	DEFAULT_USB_DEV,
+#endif
 	NULL
 };
 #elif defined(__OpenBSD__) && defined(WSCONS_SUPPORT)
@@ -101,7 +104,11 @@
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
@@ -180,10 +187,31 @@
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
@@ -191,10 +219,20 @@
     if (pInfo->fd == -1)
 	return NULL;
 
+#ifdef XPS2_SUPPORT
     /* set the driver operation level, if applicable */
+    if ((dev = xf86FindOptionValue(pInfo->options, "Device"))) {
+	if (!strncmp(dev, DEFAULT_PS2_DEV, 8))
+	    i = 2;
+	else
+	    i = 1;
+	ioctl(pInfo->fd, MOUSE_SETLEVEL, &i);
+    }
+#else
     i = 1;
     ioctl(pInfo->fd, MOUSE_SETLEVEL, &i);
-    
+#endif
+
     /* interrogate the driver and get some intelligence on the device. */
     hw.iftype = MOUSE_IF_UNKNOWN;
     hw.model = MOUSE_MODEL_GENERIC;
@@ -210,9 +248,18 @@
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
@@ -235,41 +282,41 @@
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
@@ -309,15 +356,12 @@
 		    devMouse = FALSE;
 		}
 		close(fd);
-		if (MousedRunning())
+		if (MousedRunning(NULL))
 		    break;
-		else {
-#ifdef DEBUG
-	    	    ErrorF("moused isn't running\n");
-#endif
-		}
 	    } else {
 		close(fd);
+		if (MousedRunning(*pdev))
+		    continue;
 		break;
 	    }
 	}
@@ -775,7 +819,9 @@
     p->CheckProtocol = CheckProtocol;
 #if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)) && defined(MOUSE_PROTO_SYSMOUSE)
     p->SetupAuto = SetupAuto;
+#ifndef XPS2_SUPPORT
     p->SetPS2Res = SetSysMouseRes;
+#endif
     p->SetBMRes = SetSysMouseRes;
     p->SetMiscRes = SetSysMouseRes;
 #endif
