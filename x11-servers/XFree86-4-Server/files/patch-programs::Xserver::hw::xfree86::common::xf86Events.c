--- programs/Xserver/hw/xfree86/common/xf86Events.c.orig	Tue Sep 21 19:22:14 2004
+++ programs/Xserver/hw/xfree86/common/xf86Events.c	Tue Sep 21 19:23:55 2004
@@ -467,7 +467,7 @@
 #if defined(SYSCONS_SUPPORT) || defined(PCVT_SUPPORT) || defined(WSCONS_SUPPORT)
   static Bool first_time = TRUE;
 #endif
-#if defined(__sparc__) && defined(__linux__)
+#if defined(__sparc__) && (defined(__linux__) || defined(__FreeBSD__))
   static int  kbdSun = -1;
 #endif
   /* Disable any keyboard processing while in suspend */
@@ -483,7 +483,7 @@
   }
 #endif
 
-#if defined (__sparc__) && defined(__linux__)
+#if defined(__sparc__) && (defined(__linux__) || defined(__FreeBSD__))
   if (kbdSun == -1) {
     if ((xf86Info.xkbmodel && !strcmp(xf86Info.xkbmodel, "sun"))
 	|| (xf86Info.xkbrules && !strcmp(xf86Info.xkbrules, "sun")))
@@ -493,7 +493,7 @@
   }
   if (kbdSun)
     goto special;
-#endif /* __sparc__ && __linux__ */
+#endif /* __sparc__ && (__linux__ || __FreeBSD__) */
 
 #ifdef __linux__
   if (xf86Info.kbdCustomKeycodes) {
@@ -543,7 +543,7 @@
       }
     } else
 #endif /* i386 && SVR4 */
-    {
+    if (!xf86IsPc98()) {
       switch (scanCode) {
       case 0x59:        scanCode = KEY_0x59; break;
       case 0x5a:        scanCode = KEY_0x5A; break;
@@ -655,10 +655,12 @@
    * they need to get the same key code as the base key on the same
    * physical keyboard key.
    */
-  if (scanCode == KEY_SysReqest)
-    scanCode = KEY_Print;
-  else if (scanCode == KEY_Break)
-    scanCode = KEY_Pause;
+  if (!xf86IsPc98()) {
+    if (scanCode == KEY_SysReqest)
+      scanCode = KEY_Print;
+    else if (scanCode == KEY_Break)
+      scanCode = KEY_Pause;
+  }
 #endif
   
   /*
@@ -695,7 +697,7 @@
     }
   }
 #endif
-#if defined (__sparc__) && defined(__linux__)
+#if defined(__sparc__) && (defined(__linux__) || defined(__FreeBSD__))
 special:
   if (kbdSun) {
     switch (scanCode) {
@@ -729,7 +731,7 @@
      */
     scanCode--;
   }
-#endif /* defined (__sparc__) && defined(__linux__) */
+#endif /* __sparc__ && (__linux__ || __FreeBSD__) */
 
 #ifdef XKB
   if ((xf86Info.ddxSpecialKeys == SKWhenNeeded &&
