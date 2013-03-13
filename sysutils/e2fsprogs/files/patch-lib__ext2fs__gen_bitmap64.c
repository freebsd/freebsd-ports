--- ./lib/ext2fs/gen_bitmap64.c.orig	2013-03-13 09:07:19.000000000 +0100
+++ ./lib/ext2fs/gen_bitmap64.c	2013-03-13 09:07:37.000000000 +0100
@@ -657,7 +657,7 @@
 	if ((block < bmap->start) || (block+num-1 > bmap->end)) {
 		ext2fs_warn_bitmap(EXT2_ET_BAD_BLOCK_TEST, block,
 				   bmap->description);
-		return;
+		return EINVAL;
 	}
 
 	return bmap->bitmap_ops->test_clear_bmap_extent(bmap, block, num);
