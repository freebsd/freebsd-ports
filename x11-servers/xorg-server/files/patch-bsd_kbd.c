--- hw/xfree86/os-support/bsd/bsd_kbd.c.orig	Mon Oct  3 18:46:14 2005
+++ hw/xfree86/os-support/bsd/bsd_kbd.c	Fri Sep 29 23:26:17 2006
@@ -75,6 +75,17 @@
     KbdDevPtr pKbd = (KbdDevPtr) pInfo->private;
     int real_leds = 0;
 
+#if defined (SYSCONS_SUPPORT)
+    if (pKbd->sunKbd) {
+  	if (leds & 0x08) real_leds |= XLED1;
+  	if (leds & 0x04) real_leds |= XLED4;
+  	if (leds & 0x02) real_leds |= XLED3;
+  	if (leds & 0x01) real_leds |= XLED2;
+        leds = real_leds;
+        real_leds = 0;
+    }
+#endif
+
 #ifdef LED_CAP
     if (leds & XLED1)  real_leds |= LED_CAP;
 #endif
@@ -83,7 +94,11 @@
 #endif
 #ifdef LED_SCR
     if (leds & XLED3)  real_leds |= LED_SCR;
+#ifdef LED_COMP
+    if (leds & XLED4)  real_leds |= LED_COMP;
+#else
     if (leds & XLED4)  real_leds |= LED_SCR;
+#endif
 #endif
 
     switch (pKbd->consType) {
