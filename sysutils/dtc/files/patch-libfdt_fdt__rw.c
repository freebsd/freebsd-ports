--- libfdt/fdt_rw.c.orig	2020-03-04 06:14:58 UTC
+++ libfdt/fdt_rw.c
@@ -435,7 +435,7 @@ int fdt_open_into(const void *fdt, void *buf, int bufs
 			return struct_size;
 	}
 
-	if (can_assume(LIBFDT_ORDER) |
+	if (can_assume(LIBFDT_ORDER) ||
 	    !fdt_blocks_misordered_(fdt, mem_rsv_size, struct_size)) {
 		/* no further work necessary */
 		err = fdt_move(fdt, buf, bufsize);
