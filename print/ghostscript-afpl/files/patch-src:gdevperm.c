--- src/gdevperm.c.orig	Fri Jun 18 16:00:47 2004
+++ src/gdevperm.c	Fri Dec 31 18:06:42 2004
@@ -289,7 +289,7 @@
 	(strncmp((const char *)name, (const char *)str, name_size) == 0))
 
 private int
-perm_get_color_comp_index(const gx_device *pdev, const char *pname,
+perm_get_color_comp_index(gx_device *pdev, const char *pname,
 					int name_size, int component_type)
 {
     const gx_device_perm_t * const dev = (const gx_device_perm_t *)pdev;
