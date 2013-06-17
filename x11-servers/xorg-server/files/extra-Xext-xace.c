From 6dae7f3792611aace1df0cca63bf50c50d93de43 Mon Sep 17 00:00:00 2001
From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Tue, 10 Aug 2010 18:30:20 +0000
Subject: xace: Invalid reference to out-of-scope data.

The callback data passed by reference to the hook was allocated on stack
within the scope of the case statement. The compiler is free to reuse
any of that stack space whilst making the function call so we may end up
passing garbage into the callback.

References:

  Bug 18451 - Xorg server 1.5.2 SEGV during XFixesGetCursorImage()
  https://bugs.freedesktop.org/show_bug.cgi?id=18451

v2: Drop the unrelated hunk that snuck in when ammending the commit
message.

Signed-off-by: Chris Wilson <chris@chris-wilson.co.uk>
Reviewed-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Signed-off-by: Keith Packard <keithp@keithp.com>
---
diff --git a/Xext/xace.c b/Xext/xace.c
index e10d837..c757cad 100644
--- Xext/xace.c
+++ Xext/xace.c
@@ -87,7 +87,18 @@ void XaceHookAuditEnd(ClientPtr ptr, int result)
  */
 int XaceHook(int hook, ...)
 {
-    pointer calldata;	/* data passed to callback */
+    union {
+	XaceResourceAccessRec res;
+	XaceDeviceAccessRec dev;
+	XaceSendAccessRec send;
+	XaceReceiveAccessRec recv;
+	XaceClientAccessRec client;
+	XaceExtAccessRec ext;
+	XaceServerAccessRec server;
+	XaceScreenAccessRec screen;
+	XaceAuthAvailRec auth;
+	XaceKeyAvailRec key;
+    } u;
     int *prv = NULL;	/* points to return value from callback */
     va_list ap;		/* argument list */
     va_start(ap, hook);
@@ -99,117 +110,86 @@ int XaceHook(int hook, ...)
      */
     switch (hook)
     {
-	case XACE_RESOURCE_ACCESS: {
-	    XaceResourceAccessRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.id = va_arg(ap, XID);
-	    rec.rtype = va_arg(ap, RESTYPE);
-	    rec.res = va_arg(ap, pointer);
-	    rec.ptype = va_arg(ap, RESTYPE);
-	    rec.parent = va_arg(ap, pointer);
-	    rec.access_mode = va_arg(ap, Mask);
-	    rec.status = Success; /* default allow */
-	    calldata = &rec;
-	    prv = &rec.status;
+	case XACE_RESOURCE_ACCESS:
+	    u.res.client = va_arg(ap, ClientPtr);
+	    u.res.id = va_arg(ap, XID);
+	    u.res.rtype = va_arg(ap, RESTYPE);
+	    u.res.res = va_arg(ap, pointer);
+	    u.res.ptype = va_arg(ap, RESTYPE);
+	    u.res.parent = va_arg(ap, pointer);
+	    u.res.access_mode = va_arg(ap, Mask);
+	    u.res.status = Success; /* default allow */
+	    prv = &u.res.status;
 	    break;
-	}
-	case XACE_DEVICE_ACCESS: {
-	    XaceDeviceAccessRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.dev = va_arg(ap, DeviceIntPtr);
-	    rec.access_mode = va_arg(ap, Mask);
-	    rec.status = Success; /* default allow */
-	    calldata = &rec;
-	    prv = &rec.status;
+	case XACE_DEVICE_ACCESS:
+	    u.dev.client = va_arg(ap, ClientPtr);
+	    u.dev.dev = va_arg(ap, DeviceIntPtr);
+	    u.dev.access_mode = va_arg(ap, Mask);
+	    u.dev.status = Success; /* default allow */
+	    prv = &u.dev.status;
 	    break;
-	}
-	case XACE_SEND_ACCESS: {
-	    XaceSendAccessRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.dev = va_arg(ap, DeviceIntPtr);
-	    rec.pWin = va_arg(ap, WindowPtr);
-	    rec.events = va_arg(ap, xEventPtr);
-	    rec.count = va_arg(ap, int);
-	    rec.status = Success; /* default allow */
-	    calldata = &rec;
-	    prv = &rec.status;
+	case XACE_SEND_ACCESS:
+	    u.send.client = va_arg(ap, ClientPtr);
+	    u.send.dev = va_arg(ap, DeviceIntPtr);
+	    u.send.pWin = va_arg(ap, WindowPtr);
+	    u.send.events = va_arg(ap, xEventPtr);
+	    u.send.count = va_arg(ap, int);
+	    u.send.status = Success; /* default allow */
+	    prv = &u.send.status;
 	    break;
-	}
-	case XACE_RECEIVE_ACCESS: {
-	    XaceReceiveAccessRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.pWin = va_arg(ap, WindowPtr);
-	    rec.events = va_arg(ap, xEventPtr);
-	    rec.count = va_arg(ap, int);
-	    rec.status = Success; /* default allow */
-	    calldata = &rec;
-	    prv = &rec.status;
+	case XACE_RECEIVE_ACCESS:
+	    u.recv.client = va_arg(ap, ClientPtr);
+	    u.recv.pWin = va_arg(ap, WindowPtr);
+	    u.recv.events = va_arg(ap, xEventPtr);
+	    u.recv.count = va_arg(ap, int);
+	    u.recv.status = Success; /* default allow */
+	    prv = &u.recv.status;
 	    break;
-	}
-	case XACE_CLIENT_ACCESS: {
-	    XaceClientAccessRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.target = va_arg(ap, ClientPtr);
-	    rec.access_mode = va_arg(ap, Mask);
-	    rec.status = Success; /* default allow */
-	    calldata = &rec;
-	    prv = &rec.status;
+	case XACE_CLIENT_ACCESS:
+	    u.client.client = va_arg(ap, ClientPtr);
+	    u.client.target = va_arg(ap, ClientPtr);
+	    u.client.access_mode = va_arg(ap, Mask);
+	    u.client.status = Success; /* default allow */
+	    prv = &u.client.status;
 	    break;
-	}
-	case XACE_EXT_ACCESS: {
-	    XaceExtAccessRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.ext = va_arg(ap, ExtensionEntry*);
-	    rec.access_mode = DixGetAttrAccess;
-	    rec.status = Success; /* default allow */
-	    calldata = &rec;
-	    prv = &rec.status;
+	case XACE_EXT_ACCESS:
+	    u.ext.client = va_arg(ap, ClientPtr);
+	    u.ext.ext = va_arg(ap, ExtensionEntry*);
+	    u.ext.access_mode = DixGetAttrAccess;
+	    u.ext.status = Success; /* default allow */
+	    prv = &u.ext.status;
 	    break;
-	}
-	case XACE_SERVER_ACCESS: {
-	    XaceServerAccessRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.access_mode = va_arg(ap, Mask);
-	    rec.status = Success; /* default allow */
-	    calldata = &rec;
-	    prv = &rec.status;
+	case XACE_SERVER_ACCESS:
+	    u.server.client = va_arg(ap, ClientPtr);
+	    u.server.access_mode = va_arg(ap, Mask);
+	    u.server.status = Success; /* default allow */
+	    prv = &u.server.status;
 	    break;
-	}
 	case XACE_SCREEN_ACCESS:
-	case XACE_SCREENSAVER_ACCESS: {
-	    XaceScreenAccessRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.screen = va_arg(ap, ScreenPtr);
-	    rec.access_mode = va_arg(ap, Mask);
-	    rec.status = Success; /* default allow */
-	    calldata = &rec;
-	    prv = &rec.status;
+	case XACE_SCREENSAVER_ACCESS:
+	    u.screen.client = va_arg(ap, ClientPtr);
+	    u.screen.screen = va_arg(ap, ScreenPtr);
+	    u.screen.access_mode = va_arg(ap, Mask);
+	    u.screen.status = Success; /* default allow */
+	    prv = &u.screen.status;
 	    break;
-	}
-	case XACE_AUTH_AVAIL: {
-	    XaceAuthAvailRec rec;
-	    rec.client = va_arg(ap, ClientPtr);
-	    rec.authId = va_arg(ap, XID);
-	    calldata = &rec;
+	case XACE_AUTH_AVAIL:
+	    u.auth.client = va_arg(ap, ClientPtr);
+	    u.auth.authId = va_arg(ap, XID);
 	    break;
-	}
-	case XACE_KEY_AVAIL: {
-	    XaceKeyAvailRec rec;
-	    rec.event = va_arg(ap, xEventPtr);
-	    rec.keybd = va_arg(ap, DeviceIntPtr);
-	    rec.count = va_arg(ap, int);
-	    calldata = &rec;
+	case XACE_KEY_AVAIL:
+	    u.key.event = va_arg(ap, xEventPtr);
+	    u.key.keybd = va_arg(ap, DeviceIntPtr);
+	    u.key.count = va_arg(ap, int);
 	    break;
-	}
-	default: {
+	default:
 	    va_end(ap);
 	    return 0;	/* unimplemented hook number */
-	}
     }
     va_end(ap);
  
     /* call callbacks and return result, if any. */
-    CallCallbacks(&XaceHooks[hook], calldata);
+    CallCallbacks(&XaceHooks[hook], &u);
     return prv ? *prv : Success;
 }
 
--
cgit v0.9.0.2-2-gbebe
