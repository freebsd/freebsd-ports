--- commonc.c.orig	2019-04-11 17:46:50.000000000 +0300
+++ commonc.c	2019-05-12 03:52:33.503858000 +0300
@@ -386,6 +386,8 @@
 	CPU_L2_CACHE_INCLUSIVE = -1;
 	CPU_L3_CACHE_INCLUSIVE = -1;
 	CPU_L4_CACHE_INCLUSIVE = -1;
+
+#if HWLOC_API_VERSION >= 0x00020000
 	for (depth = 0; depth < hwloc_topology_get_depth (hwloc_topology); depth++) {
 		for (i = 0; i < (int) hwloc_get_nbobjs_by_depth (hwloc_topology, depth); i++) {
 			hwloc_obj_t obj;
@@ -423,6 +425,7 @@
 			}
 		}
 	}
+#endif
 
 /* Overwrite the cache info calculated via CPUID as hwloc's info is more detailed and I believe more reliable. */
 /* We are transitioning away from using the cache size global variables computed by the CPUID code. */
