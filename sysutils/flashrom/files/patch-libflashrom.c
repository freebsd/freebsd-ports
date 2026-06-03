--- libflashrom.c.orig	2025-11-05 09:42:11 UTC
+++ libflashrom.c
@@ -455,6 +455,7 @@ bool flashrom_flag_get(const struct flashrom_flashctx 
 	}
 }
 
+#ifdef __FLASHROM_LITTLE_ENDIAN__
 static int compare_region_with_dump(const struct romentry *const a, const struct romentry *const b)
 {
 	if (a->region.start != b->region.end
@@ -463,6 +464,7 @@ static int compare_region_with_dump(const struct romen
 			return 1;
 	return 0;
 }
+#endif
 
 int flashrom_layout_read_from_ifd(struct flashrom_layout **const layout, struct flashctx *const flashctx,
 				  const void *const dump, const size_t len)
