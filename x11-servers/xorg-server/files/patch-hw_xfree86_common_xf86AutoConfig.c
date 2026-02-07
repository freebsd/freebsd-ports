* Try using modesetting driver before falling back to scfb or vesa
*
* Use our scfb driver as fallback instead of Linux's fbdev
*
--- hw/xfree86/common/xf86AutoConfig.c.orig	2022-01-02 23:41:56.000000000 +0100
+++ hw/xfree86/common/xf86AutoConfig.c	2022-06-29 11:57:25.400030000 +0200
@@ -294,7 +294,7 @@ listPossibleVideoDrivers(XF86MatchedDrivers *md)
     xf86PciMatchDriver(md);
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
     xf86AddMatchedDriver(md, "modesetting");
 #endif
 
@@ -302,8 +302,10 @@ listPossibleVideoDrivers(XF86MatchedDrivers *md)
     /* Fallback to platform default frame buffer driver */
 #if !defined(__linux__) && defined(__sparc__)
     xf86AddMatchedDriver(md, "wsfb");
-#else
+#elif defined(__linux__)
     xf86AddMatchedDriver(md, "fbdev");
+#elif defined(__FreeBSD__)
+    xf86AddMatchedDriver(md, "scfb");
 #endif
 #endif                          /* !__sun */
 
