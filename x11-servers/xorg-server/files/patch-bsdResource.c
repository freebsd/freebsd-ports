--- hw/xfree86/os-support/bsd/bsdResource.c.orig	2008-07-19 12:47:13.000000000 +0100
+++ hw/xfree86/os-support/bsd/bsdResource.c	2008-07-19 12:52:03.000000000 +0100
@@ -19,7 +19,7 @@
 
 #ifdef INCLUDE_XF86_NO_DOMAIN
 
-#if defined(__alpha__) || defined(__sparc64__) || defined(__amd64__) || defined(__x86_64__)
+#if defined(__alpha__) || defined(__amd64__) || defined(__x86_64__)
 
 resPtr
 xf86AccResFromOS(resPtr ret)
@@ -60,7 +60,7 @@
     return ret;
 }
 
-#elif defined(__powerpc__)
+#elif defined(__powerpc__) || defined(__sparc__) || defined(__sparc64__)
 
 resPtr
 xf86AccResFromOS(resPtr ret)
@@ -77,7 +77,11 @@
     ret = xf86AddResToList(ret, &range, -1);
     RANGE(range, 0x00000000, 0x00000000, ResExcIoBlock);
     ret = xf86AddResToList(ret, &range, -1);
+#if defined(__sparc__) || defined(__sparc64__)
+    RANGE(range, 0x00ffffff, 0x00ffffff, ResExcIoBlock);
+#else
     RANGE(range, 0x0000ffff, 0x0000ffff, ResExcIoBlock);
+#endif
     ret = xf86AddResToList(ret, &range, -1);
 
     return ret;
