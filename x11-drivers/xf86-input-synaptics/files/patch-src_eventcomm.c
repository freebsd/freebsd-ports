--- src/eventcomm.c.orig	2016-09-30 07:09:32 UTC
+++ src/eventcomm.c
@@ -421,10 +421,15 @@ event_get_abs(struct libevdev *evdev, in
     /* We dont trust a zero fuzz as it probably is just a lazy value */
     if (fuzz && abs->fuzz > 0)
         *fuzz = abs->fuzz;
+#ifdef __linux__
 #if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,30)
     if (res)
         *res = abs->resolution;
 #endif
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    if (res)
+        *res = abs->resolution;
+#endif

     return 0;
 }
