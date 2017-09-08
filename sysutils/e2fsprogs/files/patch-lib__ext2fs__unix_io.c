commit 649dbee84cf208244db7195d40e7fe57ddbea57a
Author: Matthias Andree <matthias.andree@gmx.de>
Date:   Sun Aug 27 14:09:52 2017 +0200

    Always obtain alignment on FreeBSD.

diff --git a/lib/ext2fs/unix_io.c b/lib/ext2fs/unix_io.c
index 64141954..65f237ef 100644
--- ./lib/ext2fs/unix_io.c
+++ ./lib/ext2fs/unix_io.c
@@ -636,7 +636,7 @@ static errcode_t unix_open_channel(const char *name, int fd,
 #endif
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-	if (io->flags & CHANNEL_FLAGS_BLOCK_DEVICE) {
+	{
 		int dio_align = ext2fs_get_dio_alignment(fd);
 
 		if (io->align < dio_align)
