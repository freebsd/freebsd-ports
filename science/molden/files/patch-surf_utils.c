--- surf/utils.c.orig	2019-06-28 03:23:08 UTC
+++ surf/utils.c
@@ -76,6 +76,7 @@ find_ray_sphere_int  computes the intersection of a ra
 uses method given in Graphics Gems I, pp 388-389.
 the direction vector of the ray need not be normalized.
 ----------------------------------------------------------------------------------*/
+void
 find_ray_sphere_int(int_point, ray_pt, ray_dir, center, radius)
 float			int_point[3], center[3];
 float			ray_pt[3], ray_dir[3];
