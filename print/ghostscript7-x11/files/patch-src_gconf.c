--- src/gconf.c.orig	2003-01-17 00:49:00 UTC
+++ src/gconf.c
@@ -81,7 +81,8 @@
 /* Set up the device table. */
 #define device_(dev) (const gx_device *)&dev,
 #define device2_(dev) &dev,
-private const gx_device *const gx_device_list[] = {
+static const gx_device *gx_device_list[1024] = {
+  /* as shared library are adding drivers here, so removed constness */
 #include "gconf.h"
 	 0
 };
@@ -149,9 +150,29 @@ int
 gs_lib_device_list(const gx_device * const **plist,
 		   gs_memory_struct_type_t ** pst)
 {
+    int i;
+
     if (plist != 0)
 	*plist = gx_device_list;
     if (pst != 0)
 	*pst = NULL;
-    return countof(gx_device_list) - 1;
+
+    for (i = 0; i < countof(gx_device_list) - 1; ++i)
+      if (!gx_device_list[i])
+        break;
+    return i;
 }
+
+#ifdef GS_DEVS_SHARED
+void
+gs_lib_register_device(const gx_device *dev)
+{
+  int i;
+
+  for (i = 0; i < countof(gx_device_list) - 1; ++i)
+    if (!gx_device_list[i]) {
+      gx_device_list[i] = dev;
+      return;
+    }
+}
+#endif
