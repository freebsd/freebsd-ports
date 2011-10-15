--- ./p4.c.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./p4.c	2011-10-14 22:36:47.000000000 -0400
@@ -175,8 +175,10 @@
 		Wprintf("%s CACHE %s %s Error\n", type, level,
 				get_RRRR_str((mca & CACHE_RRRR_MASK) >> 
 					      CACHE_RRRR_SHIFT));
+#ifdef __Linux__
 		if (track == 2)
 			run_yellow_trigger(cpu, typenum, levelnum, type, level, socket);
+#endif
 	} else if (test_prefix(10, mca)) {
 		if (mca == 0x400)
 			Wprintf("Internal Timer error\n");
