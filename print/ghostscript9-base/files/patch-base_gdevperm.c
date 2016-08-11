--- base/gdevperm.c.orig	2012-08-08 08:01:36 UTC
+++ base/gdevperm.c
@@ -287,7 +287,7 @@ perm_get_color_mapping_procs(const gx_de
         (strncmp((const char *)name, (const char *)str, name_size) == 0))
 
 static int
-perm_get_color_comp_index(const gx_device *pdev, const char *pname,
+perm_get_color_comp_index(gx_device *pdev, const char *pname,
                                         int name_size, int component_type)
 {
     const gx_device_perm_t * const dev = (const gx_device_perm_t *)pdev;
@@ -334,7 +334,6 @@ static int
 perm_decode_color(gx_device *dev, gx_color_index color, gx_color_value *out)
 {
     int bpc = 8;
-    int drop = sizeof(gx_color_value) * 8 - bpc;
     int mask = (1 << bpc) - 1;
     int i = 0;
     int ncomp = dev->color_info.num_components;
