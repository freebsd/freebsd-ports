--- programs/Xserver/hw/xfree86/common/xf86Events.c.orig	Sun Sep 26 04:17:42 2004
+++ programs/Xserver/hw/xfree86/common/xf86Events.c	Sun Sep 26 04:17:25 2004
@@ -448,7 +448,7 @@
 #if defined(SYSCONS_SUPPORT) || defined(PCVT_SUPPORT) || defined(WSCONS_SUPPORT)
   static Bool first_time = TRUE;
 #endif
-#if defined(__sparc__) && defined(__linux__)
+#if defined(__sparc__) && (defined(__linux__) || defined(__FreeBSD__))
   static int  kbdSun = -1;
 #endif
   /* Disable any keyboard processing while in suspend */
@@ -464,7 +464,7 @@
   }
 #endif
 
-#if defined (__sparc__) && defined(__linux__)
+#if defined(__sparc__) && (defined(__linux__) || defined(__FreeBSD__))
   if (kbdSun == -1) {
     if ((xf86Info.xkbmodel && !strcmp(xf86Info.xkbmodel, "sun"))
 	|| (xf86Info.xkbrules && !strcmp(xf86Info.xkbrules, "sun")))
@@ -474,7 +474,7 @@
   }
   if (kbdSun)
     goto special;
-#endif /* __sparc__ && __linux__ */
+#endif /* __sparc__ && (__linux__ || __FreeBSD__) */
 
 #ifdef __linux__
   if (xf86Info.kbdCustomKeycodes) {
@@ -525,6 +525,7 @@
     } else
 #endif /* i386 && SVR4 */
     {
+      if (!xf86IsPc98()) {
       switch (scanCode) {
       case 0x59:        scanCode = KEY_0x59; break;
       case 0x5a:        scanCode = KEY_0x5A; break;
@@ -555,6 +556,7 @@
       case 0x75:        scanCode = KEY_0x75; break;
       case 0x76:        scanCode = KEY_0x76; break;
       }
+      }  /*  end if (!xf86IsPc98())  */
     }
   }
 
@@ -636,10 +638,12 @@
    * they need to get the same key code as the base key on the same
    * physical keyboard key.
    */
+  if (!xf86IsPc98()) {
   if (scanCode == KEY_SysReqest)
     scanCode = KEY_Print;
   else if (scanCode == KEY_Break)
     scanCode = KEY_Pause;
+  }
 #endif
   
   /*
@@ -676,7 +680,7 @@
     }
   }
 #endif
-#if defined (__sparc__) && defined(__linux__)
+#if defined(__sparc__) && (defined(__linux__) || defined(__FreeBSD__))
 special:
   if (kbdSun) {
     switch (scanCode) {
@@ -710,7 +714,7 @@
      */
     scanCode--;
   }
-#endif /* defined (__sparc__) && defined(__linux__) */
+#endif /* __sparc__ && (__linux__ || __FreeBSD__) */
 
 #ifdef XKB
   if ((xf86Info.ddxSpecialKeys == SKWhenNeeded &&
