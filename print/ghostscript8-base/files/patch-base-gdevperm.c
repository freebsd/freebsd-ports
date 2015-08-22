--- base/gdevperm.c.orig	Tue Sep 25 22:31:24 2007
+++ base/gdevperm.c	Sat Nov 24 15:11:12 2007
@@ -286,7 +286,7 @@
 	(strncmp((const char *)name, (const char *)str, name_size) == 0))
 
 static int
-perm_get_color_comp_index(const gx_device *pdev, const char *pname,
+perm_get_color_comp_index(gx_device *pdev, const char *pname,
 					int name_size, int component_type)
 {
     const gx_device_perm_t * const dev = (const gx_device_perm_t *)pdev;
