--- base/gdevperm.c.orig	2007-09-25 13:31:24 UTC
+++ base/gdevperm.c
@@ -286,7 +286,7 @@ perm_get_color_mapping_procs(const gx_de
 	(strncmp((const char *)name, (const char *)str, name_size) == 0))
 
 static int
-perm_get_color_comp_index(const gx_device *pdev, const char *pname,
+perm_get_color_comp_index(gx_device *pdev, const char *pname,
 					int name_size, int component_type)
 {
     const gx_device_perm_t * const dev = (const gx_device_perm_t *)pdev;
