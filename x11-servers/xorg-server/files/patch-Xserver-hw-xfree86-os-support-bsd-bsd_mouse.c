--- hw/xfree86/os-support/bsd/bsd_mouse.c.orig	2007-08-23 15:05:48.000000000 -0400
+++ hw/xfree86/os-support/bsd/bsd_mouse.c	2008-03-28 13:49:17.000000000 -0400
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
@@ -184,6 +187,7 @@
 static const char *
 SetupAuto(InputInfoPtr pInfo, int *protoPara)
 {
+    char *dev;
     int i;
     mousehw_t hw;
     mousemode_t mode;
@@ -192,9 +196,12 @@
 	return NULL;
 
     /* set the driver operation level, if applicable */
-    i = 1;
-    ioctl(pInfo->fd, MOUSE_SETLEVEL, &i);
-    
+    if ((dev = xf86FindOptionValue(pInfo->options, "Device")) &&
+	!strcmp(dev, DEFAULT_SYSMOUSE_DEV)) {
+	i = 1;
+	ioctl(pInfo->fd, MOUSE_SETLEVEL, &i);
+    }
+
     /* interrogate the driver and get some intelligence on the device. */
     hw.iftype = MOUSE_IF_UNKNOWN;
     hw.model = MOUSE_MODEL_GENERIC;
@@ -210,8 +217,8 @@
 		    protoPara[0] = mode.syncmask[0];
 		    protoPara[1] = mode.syncmask[1];
 		}
-		xf86MsgVerb(X_INFO, 3, "%s: SetupAuto: protocol is %s\n",
-			    pInfo->name, devproto[i].name);
+		xf86MsgVerb(X_INFO, 3, "%s: SetupAuto: protocol is %s, level is %d\n",
+			    pInfo->name, devproto[i].name, mode.level);
 		return devproto[i].name;
 	    }
 	}
@@ -222,6 +229,7 @@
 static void
 SetSysMouseRes(InputInfoPtr pInfo, const char *protocol, int rate, int res)
 {
+    char *dev;
     mousemode_t mode;
     MouseDevPtr pMse;
 
@@ -231,11 +239,11 @@
     mode.resolution = res > 0 ? res : -1;
     mode.accelfactor = -1;
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-    if (pMse->autoProbe ||
-	(protocol && xf86NameCmp(protocol, "SysMouse") == 0)) {
+    if ((dev = xf86FindOptionValue(pInfo->options, "Device")) &&
+	!strcmp(dev, DEFAULT_SYSMOUSE_DEV)) {
 	/*
 	 * As the FreeBSD sysmouse driver defaults to protocol level 0
-	 * everytime it is opened we enforce protocol level 1 again at
+	 * everytime it is closed we enforce protocol level 1 again at
 	 * this point.
 	 */
 	mode.level = 1;
@@ -249,27 +257,29 @@
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
@@ -309,15 +319,12 @@
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
