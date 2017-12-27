Upstreamed, remove after the next release:
  - https://github.com/jarun/nnn/pull/70
  - https://github.com/jarun/nnn/pull/69

--- nnn.c.orig	2017-12-25 13:40:20 UTC
+++ nnn.c
@@ -260,7 +260,7 @@ static char * const utils[] = {
 #ifdef __APPLE__
 	"/usr/bin/open",
 #else
-	"/usr/bin/xdg-open",
+	"xdg-open",
 #endif
 	"nlay",
 	"atool"
@@ -1544,20 +1544,22 @@ show_stats(char *fpath, char *fname, str
 	/* Show size, blocks, file type */
 #if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 	dprintf(fd, "\n    Size: %-15lld Blocks: %-10lld IO Block: %-6d %s",
+	       (long long)sb->st_size, (long long)sb->st_blocks, sb->st_blksize, desc);
 #else
 	dprintf(fd, "\n    Size: %-15ld Blocks: %-10ld IO Block: %-6ld %s",
-#endif
 	       sb->st_size, sb->st_blocks, sb->st_blksize, desc);
+#endif
 
 	/* Show containing device, inode, hardlink count */
 #if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 	sprintf(g_buf, "%xh/%ud", sb->st_dev, sb->st_dev);
 	dprintf(fd, "\n  Device: %-15s Inode: %-11llu Links: %-9hu",
+		g_buf, (unsigned long long)sb->st_ino, sb->st_nlink);
 #else
 	sprintf(g_buf, "%lxh/%lud", sb->st_dev, sb->st_dev);
 	dprintf(fd, "\n  Device: %-15s Inode: %-11lu Links: %-9lu",
-#endif
 		g_buf, sb->st_ino, sb->st_nlink);
+#endif
 
 	/* Show major, minor number for block or char device */
 	if (perms[0] == 'b' || perms[0] == 'c')
