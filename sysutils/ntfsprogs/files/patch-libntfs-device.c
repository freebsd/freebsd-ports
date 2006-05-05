--- libntfs/device.c	Sat Sep  4 13:16:32 2004
+++ libntfs/device.c	Mon Jul 11 23:27:55 2005
@@ -441,10 +441,10 @@
  */
 static inline int ntfs_device_offset_valid(struct ntfs_device *dev, s64 ofs)
 {
-	char ch;
+	char ch[512];
 
 	if (dev->d_ops->seek(dev, ofs, SEEK_SET) >= 0 &&
-			dev->d_ops->read(dev, &ch, 1) == 1)
+			dev->d_ops->read(dev, &ch, 512) > 0)
 		return 0;
 	return -1;
 }
