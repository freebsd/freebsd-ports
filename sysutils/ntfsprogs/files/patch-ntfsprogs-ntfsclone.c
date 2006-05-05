--- ntfsprogs/ntfsclone.c	Mon Jul 25 12:31:30 2005
+++ ntfsprogs/ntfsclone.c	Mon Jul 25 12:33:32 2005
@@ -1080,9 +1080,9 @@
 
 static int device_offset_valid(int fd, s64 ofs)
 {
-	char ch;
+	char ch[512];
 
-	if (lseek(fd, ofs, SEEK_SET) >= 0 && read(fd, &ch, 1) == 1)
+	if (lseek(fd, ofs, SEEK_SET) >= 0 && read(fd, &ch, 512) > 0)
 		return 0;
 	return -1;
 }
