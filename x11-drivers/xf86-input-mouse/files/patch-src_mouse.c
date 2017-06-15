--- src/mouse.c.orig	2016-09-06 03:53:31 UTC
+++ src/mouse.c
@@ -304,13 +304,39 @@ MouseCommonOptions(InputInfoPtr pInfo)
 
     pMse = pInfo->private;
 
-    pMse->buttons = xf86SetIntOption(pInfo->options, "Buttons", 0);
+    i = xf86SetIntOption(pInfo->options, "Buttons", 0);
+    if (i != 0)
+        pMse->buttons = i;
     if (!pMse->buttons) {
         pMse->buttons = MSE_DFLTBUTTONS;
         buttons_from = X_DEFAULT;
     }
     origButtons = pMse->buttons;
 
+    s = xf86SetStrOption(pInfo->options, "ButtonMapping", NULL);
+    if (s) {
+        int b, n = 0;
+        char *s1 = s;
+        /* keep getting numbers which are buttons */
+        while (s1 && n < MSE_MAXBUTTONS && (b = strtol(s1, &s1, 10)) != 0) {
+            /* check sanity for a button */
+            if (b < 0 || b > MSE_MAXBUTTONS) {
+                xf86Msg(X_WARNING,
+                        "ButtonMapping: Invalid button number = %d\n", b);
+                break;
+           };
+           pMse->buttonMap[n++] = 1 << (b-1);
+           if (b > pMse->buttons) pMse->buttons = b;
+        }
+        free(s);
+    }
+    /* get maximum of mapped buttons */
+    for (i = pMse->buttons-1; i >= 0; i--) {
+        int f = ffs (pMse->buttonMap[i]);
+        if (f > pMse->buttons)
+            pMse->buttons = f;
+    }
+
     pMse->emulate3Buttons = xf86SetBoolOption(pInfo->options,
                                               "Emulate3Buttons", FALSE);
     if (!xf86FindOptionValue(pInfo->options,"Emulate3Buttons")) {
@@ -322,6 +348,8 @@ MouseCommonOptions(InputInfoPtr pInfo)
                                              "Emulate3Timeout", 50);
     if (pMse->emulate3Buttons || pMse->emulate3ButtonsSoft) {
         MessageType from = X_CONFIG;
+	if (pMse->buttons < 3)
+            pMse->buttons = 3;
         if (pMse->emulate3ButtonsSoft)
             from = X_DEFAULT;
         xf86Msg(from, "%s: Emulate3Buttons, Emulate3Timeout: %d\n",
@@ -329,6 +357,8 @@ MouseCommonOptions(InputInfoPtr pInfo)
     }
 
     pMse->chordMiddle = xf86SetBoolOption(pInfo->options, "ChordMiddle", FALSE);
+    if (pMse->chordMiddle && pMse->buttons < 3)
+	    pMse->buttons = 3;
     pMse->flipXY = xf86SetBoolOption(pInfo->options, "FlipXY", FALSE);
     if (xf86SetBoolOption(pInfo->options, "InvX", FALSE)) {
         pMse->invX = -1;
@@ -339,7 +369,7 @@ MouseCommonOptions(InputInfoPtr pInfo)
     } else
         pMse->invY = 1;
     pMse->angleOffset = xf86SetIntOption(pInfo->options, "AngleOffset", 0);
-
+    pMse->sensitivity = xf86SetRealOption(pInfo->options, "Sensitivity", 1.0);
 
     if (pMse->pDragLock)
         free(pMse->pDragLock);
@@ -449,14 +479,17 @@ MouseCommonOptions(InputInfoPtr pInfo)
         free(s);
     }
 
-    s = xf86SetStrOption(pInfo->options, "ZAxisMapping", "4 5");
+    s = xf86SetStrOption(pInfo->options, "ZAxisMapping",
+        pMse->hasZ ? ( pMse->hasW ? "4 5 6 7" : "4 5" ) : "off");
     if (s) {
         int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
         char *msg = NULL;
 
         pMse->negativeZ = pMse->positiveZ = MSE_NOAXISMAP;
         pMse->negativeW = pMse->positiveW = MSE_NOAXISMAP;
-        if (!xf86NameCmp(s, "x")) {
+        if (!xf86NameCmp(s, "off")) {
+            msg = xstrdup("off");
+	} else if (!xf86NameCmp(s, "x")) {
             pMse->negativeZ = pMse->positiveZ = MSE_MAPTOX;
             msg = xstrdup("X axis");
         } else if (!xf86NameCmp(s, "y")) {
@@ -605,29 +638,6 @@ MouseCommonOptions(InputInfoPtr pInfo)
                 pInfo->name, wheelButton, pMse->wheelInertia,
                 pMse->wheelButtonTimeout);
     }
-    s = xf86SetStrOption(pInfo->options, "ButtonMapping", NULL);
-    if (s) {
-       int b, n = 0;
-       char *s1 = s;
-       /* keep getting numbers which are buttons */
-       while (s1 && n < MSE_MAXBUTTONS && (b = strtol(s1, &s1, 10)) != 0) {
-           /* check sanity for a button */
-           if (b < 0 || b > MSE_MAXBUTTONS) {
-               xf86Msg(X_WARNING,
-                       "ButtonMapping: Invalid button number = %d\n", b);
-               break;
-           };
-           pMse->buttonMap[n++] = 1 << (b-1);
-           if (b > pMse->buttons) pMse->buttons = b;
-       }
-       free(s);
-    }
-    /* get maximum of mapped buttons */
-    for (i = pMse->buttons-1; i >= 0; i--) {
-        int f = ffs (pMse->buttonMap[i]);
-        if (f > pMse->buttons)
-            pMse->buttons = f;
-    }
     if (origButtons != pMse->buttons)
         buttons_from = X_CONFIG;
     xf86Msg(buttons_from, "%s: Buttons: %d\n", pInfo->name, pMse->buttons);
@@ -709,7 +719,6 @@ MouseHWOptions(InputInfoPtr pInfo)
     }
     pMse->sampleRate = xf86SetIntOption(pInfo->options, "SampleRate", 0);
     pMse->resolution = xf86SetIntOption(pInfo->options, "Resolution", 0);
-    mPriv->sensitivity = xf86SetRealOption(pInfo->options, "Sensitivity", 1.0);
 }
 
 static void
@@ -997,6 +1006,8 @@ MousePreInit(InputDriverPtr drv, InputIn
     /* Default Mapping: 1 2 3 8 9 10 11 ... */
     for (i = 0; i < MSE_MAXBUTTONS; i++)
         pMse->buttonMap[i] = 1 << (i > 2 && i < MSE_MAXBUTTONS-4 ? i+4 : i);
+    pMse->hasZ = 1;
+    pMse->hasW = 0;
 
     protocol = MousePickProtocol(pInfo, device, protocol, &protocolID);
 
@@ -2198,7 +2209,7 @@ MouseDoPostEvent(InputInfoPtr pInfo, int
 
     if (pMse->emulateWheel) {
         /* Emulate wheel button handling */
-        if(pMse->wheelButton == 0)
+        if (pMse->wheelButton == 0)
             wheelButtonMask = 0;
         else
             wheelButtonMask = 1 << (pMse->wheelButton - 1);
@@ -2288,6 +2299,9 @@ MouseDoPostEvent(InputInfoPtr pInfo, int
                         }
                     }
                 }
+            } else {
+                pMse->wheelXDistance = 0;
+                pMse->wheelYDistance = 0;
             }
 
             /* Absorb the mouse movement while the wheel button is pressed. */
@@ -2305,7 +2319,7 @@ MouseDoPostEvent(InputInfoPtr pInfo, int
     if (pMse->emulate3ButtonsSoft && pMse->emulate3Pending && (dx || dy))
         buttonTimer(pInfo);
 
-    if (dx || dy)
+    if ((dx || dy) && !pMse->disableXY)
         xf86PostMotionEvent(pInfo->dev, 0, 0, 2, dx, dy);
 
     if (change) {
@@ -2418,12 +2432,10 @@ MousePostEvent(InputInfoPtr pInfo, int t
                int dx, int dy, int dz, int dw)
 {
     MouseDevPtr pMse;
-    mousePrivPtr mousepriv;
     int zbutton = 0, wbutton = 0, zbuttoncount = 0, wbuttoncount = 0;
     int i, b, buttons = 0;
 
     pMse = pInfo->private;
-    mousepriv = (mousePrivPtr)pMse->mousePriv;
 
     if (pMse->protocolID == PROT_MMHIT)
         b = reverseBits(hitachMap, truebuttons);
@@ -2516,11 +2528,11 @@ MousePostEvent(InputInfoPtr pInfo, int t
 
     /* Accumulate the scaled dx, dy in the private variables
        fracdx,fracdy and return the integer number part */
-    if (mousepriv) {
-        mousepriv->fracdx += mousepriv->sensitivity*dx;
-        mousepriv->fracdy += mousepriv->sensitivity*dy;
-        mousepriv->fracdx -= ( dx=(int)(mousepriv->fracdx) );
-        mousepriv->fracdy -= ( dy=(int)(mousepriv->fracdy) );
+    if (pMse->sensitivity != 0) {
+        pMse->fracdx += pMse->sensitivity*dx;
+        pMse->fracdy += pMse->sensitivity*dy;
+        pMse->fracdx -= ( dx=(int)(pMse->fracdx) );
+        pMse->fracdy -= ( dy=(int)(pMse->fracdy) );
     }
 
     /* If mouse wheel movement has to be mapped on a button, we need to
