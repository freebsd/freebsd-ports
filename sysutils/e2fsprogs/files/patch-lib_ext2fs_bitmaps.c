# To fix bitops related crash
# patch provided by Ted Ts'o to Frantisek Holop (OpenBSD porter)

diff --git a/lib/ext2fs/bitmaps.c b/lib/ext2fs/bitmaps.c
index 696baad..843a75f 100644
--- a/lib/ext2fs/bitmaps.c
+++ b/lib/ext2fs/bitmaps.c
@@ -56,7 +56,7 @@ static errcode_t make_bitmap(__u32 start, __u32 end, __u32 real_end,
 	} else
 		bitmap->description = 0;
 
-	size = (size_t) (((bitmap->real_end - bitmap->start) / 8) + 1);
+	size = (size_t) (((bitmap->real_end - bitmap->start) / 8) + 2);
 	retval = ext2fs_get_mem(size, &bitmap->bitmap);
 	if (retval) {
 		ext2fs_free_mem(&bitmap->description);
