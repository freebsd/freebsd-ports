--- ./libntfs/device.c.orig	2007-09-26 22:28:34.000000000 +0400
+++ ./libntfs/device.c	2011-03-15 23:07:06.183948162 +0300
@@ -62,6 +62,9 @@
 #ifdef HAVE_LINUX_HDREG_H
 #include <linux/hdreg.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/disk.h>
+#endif
 
 #include "types.h"
 #include "mst.h"
@@ -599,6 +602,17 @@
 		}
 	}
 #endif
+#ifdef DIOCGMEDIASIZE 
+	{       off_t size;
+
+		if (dev->d_ops->ioctl(dev, DIOCGMEDIASIZE, &size) >= 0) {
+			ntfs_log_debug("DIOCGMEDIASIZE nr bytes = %llu (0x%llx)\n",
+					(unsigned long long)size,
+					(unsigned long long)size);
+			return (s64)size / block_size;
+		}
+	}
+#endif
 	/*
 	 * We couldn't figure it out by using a specialized ioctl,
 	 * so do binary search to find the size of the device.
@@ -627,8 +641,8 @@
  *
  * The following error codes are defined:
  *	EINVAL		Input parameter error
- *	EOPNOTSUPP	System does not support HDIO_GETGEO ioctl
- *	ENOTTY		@dev is a file or a device not supporting HDIO_GETGEO
+ *	EOPNOTSUPP	System does not support DIOCGFWSECTORS ioctl
+ *	ENOTTY		@dev is a file or a device not supporting DIOCGFWSECTORS
  */
 s64 ntfs_device_partition_start_sector_get(struct ntfs_device *dev)
 {
@@ -636,13 +650,13 @@
 		errno = EINVAL;
 		return -1;
 	}
-#ifdef HDIO_GETGEO
-	{	struct hd_geometry geo;
+#ifdef DIOCGFWSECTORS
+	{	u_int	start_sector = 0;
 
-		if (!dev->d_ops->ioctl(dev, HDIO_GETGEO, &geo)) {
-			ntfs_log_debug("HDIO_GETGEO start_sect = %lu (0x%lx)\n",
-					geo.start, geo.start);
-			return geo.start;
+		if (!dev->d_ops->ioctl(dev, DIOCGFWSECTORS, &start_sector)) {
+			ntfs_log_debug("DIOCGFWSECTORS start_sect = %lu (0x%lx)\n",
+					start_sector, start_sector);
+			return start_sector;
 		}
 	}
 #else
@@ -660,8 +674,8 @@
  *
  * The following error codes are defined:
  *	EINVAL		Input parameter error
- *	EOPNOTSUPP	System does not support HDIO_GETGEO ioctl
- *	ENOTTY		@dev is a file or a device not supporting HDIO_GETGEO
+ *	EOPNOTSUPP	System does not support DIOCGFWHEADS ioctl
+ *	ENOTTY		@dev is a file or a device not supporting DIOCGFWHEADS
  */
 int ntfs_device_heads_get(struct ntfs_device *dev)
 {
@@ -669,14 +683,13 @@
 		errno = EINVAL;
 		return -1;
 	}
-#ifdef HDIO_GETGEO
-	{	struct hd_geometry geo;
+#ifdef DIOCGFWHEADS
+	{	u_int	heads;
 
-		if (!dev->d_ops->ioctl(dev, HDIO_GETGEO, &geo)) {
-			ntfs_log_debug("HDIO_GETGEO heads = %u (0x%x)\n",
-					(unsigned)geo.heads,
-					(unsigned)geo.heads);
-			return geo.heads;
+		if (!dev->d_ops->ioctl(dev, DIOCGFWHEADS, &heads)) {
+			ntfs_log_debug("DIOCGFWHEADS heads = %u (0x%x)\n",
+					heads, heads);
+			return heads;
 		}
 	}
 #else
@@ -694,8 +707,8 @@
  *
  * The following error codes are defined:
  *	EINVAL		Input parameter error
- *	EOPNOTSUPP	System does not support HDIO_GETGEO ioctl
- *	ENOTTY		@dev is a file or a device not supporting HDIO_GETGEO
+ *	EOPNOTSUPP	System does not support DIOCGFWSECTORS ioctl
+ *	ENOTTY		@dev is a file or a device not supporting DIOCGFWSECTORS
  */
 int ntfs_device_sectors_per_track_get(struct ntfs_device *dev)
 {
@@ -703,14 +716,13 @@
 		errno = EINVAL;
 		return -1;
 	}
-#ifdef HDIO_GETGEO
-	{	struct hd_geometry geo;
+#ifdef DIOCGFWSECTORS
+	{	u_int	sptrack;
 
-		if (!dev->d_ops->ioctl(dev, HDIO_GETGEO, &geo)) {
-			ntfs_log_debug("HDIO_GETGEO sectors_per_track = %u (0x%x)\n",
-					(unsigned)geo.sectors,
-					(unsigned)geo.sectors);
-			return geo.sectors;
+		if (!dev->d_ops->ioctl(dev, DIOCGFWSECTORS, &sptrack)) {
+			ntfs_log_debug("DIOCGFWSECTORS sectors_per_track = %u (0x%x)\n",
+					sptrack, sptrack);
+			return sptrack;
 		}
 	}
 #else
@@ -728,8 +740,8 @@
  *
  * The following error codes are defined:
  *	EINVAL		Input parameter error
- *	EOPNOTSUPP	System does not support BLKSSZGET ioctl
- *	ENOTTY		@dev is a file or a device not supporting BLKSSZGET
+ *	EOPNOTSUPP	System does not support DIOCGSECTORSIZE ioctl
+ *	ENOTTY		@dev is a file or a device not supporting DIOCGSECTORSIZE
  */
 int ntfs_device_sector_size_get(struct ntfs_device *dev)
 {
@@ -737,13 +749,13 @@
 		errno = EINVAL;
 		return -1;
 	}
-#ifdef BLKSSZGET
+#ifdef	DIOCGSECTORSIZE
 	{
-		int sect_size = 0;
+		size_t sect_size = 0;
 
-		if (!dev->d_ops->ioctl(dev, BLKSSZGET, &sect_size)) {
-			ntfs_log_debug("BLKSSZGET sector size = %d bytes\n",
-					sect_size);
+		if (!dev->d_ops->ioctl(dev, DIOCGSECTORSIZE, &sect_size)) {
+			ntfs_log_debug("DIOCGSECTORSIZE sector size = %d bytes\n",
+				(int)sect_size);
 			return sect_size;
 		}
 	}
