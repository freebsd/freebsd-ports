--- programs/Xserver/hw/xfree86/common/xf86Events.c.orig	Sat Dec  6 14:24:24 2003
+++ programs/Xserver/hw/xfree86/common/xf86Events.c	Tue Aug 31 00:27:37 2004
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
@@ -676,7 +676,7 @@
     }
   }
 #endif
-#if defined (__sparc__) && defined(__linux__)
+#if defined(__sparc__) && (defined(__linux__) || defined(__FreeBSD__))
 special:
   if (kbdSun) {
     switch (scanCode) {
@@ -710,7 +710,7 @@
      */
     scanCode--;
   }
-#endif /* defined (__sparc__) && defined(__linux__) */
+#endif /* __sparc__ && (__linux__ || __FreeBSD__) */
 
 #ifdef XKB
   if ((xf86Info.ddxSpecialKeys == SKWhenNeeded &&
