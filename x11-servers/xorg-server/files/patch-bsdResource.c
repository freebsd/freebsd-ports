--- programs/Xserver/hw/xfree86/os-support/bsd/bsdResource.c.orig	Fri Apr 23 21:54:07 2004
+++ programs/Xserver/hw/xfree86/os-support/bsd/bsdResource.c	Tue May 17 00:48:36 2005
@@ -18,7 +18,7 @@
 
 #ifdef INCLUDE_XF86_NO_DOMAIN
 
-#if defined(__alpha__) || defined(__sparc64__) || defined(__amd64__)
+#if defined(__alpha__) || defined(__amd64__)
 
 resPtr
 xf86BusAccWindowsFromOS(void)
@@ -112,7 +112,7 @@
     return ret;
 }
 
-#elif defined(__powerpc__)
+#elif defined(__powerpc__) || defined(__sparc__) || defined(__sparc64__)
 
 resPtr
 xf86BusAccWindowsFromOS(void)
@@ -123,7 +123,11 @@
     RANGE(range, 0x00000000, 0xffffffff, ResExcMemBlock);
     ret = xf86AddResToList(ret, &range, -1);
 
+#if defined(__sparc__) || defined(__sparc64__)
+    RANGE(range, 0x00000000, 0x00ffffff, ResExcIoBlock);
+#else
     RANGE(range, 0x00000000, 0x0000ffff, ResExcIoBlock);
+#endif
     ret = xf86AddResToList(ret, &range, -1);
     return ret;
 }
@@ -137,7 +141,11 @@
     RANGE(range, 0x00000000, 0xffffffff, ResExcMemBlock);
     ret = xf86AddResToList(ret, &range, -1);
 
+#if defined(__sparc__) || defined(__sparc64__)
+    RANGE(range, 0x00000000, 0x00ffffff, ResExcIoBlock);
+#else
     RANGE(range, 0x00000000, 0x0000ffff, ResExcIoBlock);
+#endif
     ret = xf86AddResToList(ret, &range, -1);
     return ret;
 }
@@ -153,7 +161,11 @@
     RANGE(range, 0x00000000, 0xffffffff, ResExcMemBlock);
     ret = xf86AddResToList(ret, &range, -1);
 
+#if defined(__sparc__) || defined(__sparc64__)         
+    RANGE(range, 0x00000000, 0x00ffffff, ResExcIoBlock);
+#else
     RANGE(range, 0x00000000, 0x0000ffff, ResExcIoBlock);
+#endif
     ret = xf86AddResToList(ret, &range, -1);
     return ret;
 }
@@ -175,7 +187,11 @@
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
