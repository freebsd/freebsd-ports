--- base/gdevperm.c.orig	2011-12-06 15:37:48.000000000 +0900
+++ base/gdevperm.c	2011-12-06 15:45:20.000000000 +0900
@@ -285,7 +285,7 @@
         (strncmp((const char *)name, (const char *)str, name_size) == 0))
 
 static int
-perm_get_color_comp_index(const gx_device *pdev, const char *pname,
+perm_get_color_comp_index(gx_device *pdev, const char *pname,
                                         int name_size, int component_type)
 {
     const gx_device_perm_t * const dev = (const gx_device_perm_t *)pdev;
