--- ksim/monitors/disk/ksimdisk.cpp.orig	Mon Nov  4 11:03:53 2002
+++ ksim/monitors/disk/ksimdisk.cpp	Wed Mar 19 13:37:39 2003
@@ -248,6 +253,16 @@
 #endif
 
 #ifdef Q_OS_FREEBSD
+#if __FreeBSD_version < 500107
+#define	devstat_getdevs(fd, stats)	getdevs(stats)
+#define	devstat_selectdevs		selectdevs
+#define	bytes_read(dev)			(dev).bytes_read
+#define	bytes_written(dev)		(dev).bytes_written
+#else
+#define	bytes_read(dev)			(dev).bytes[DEVSTAT_READ]
+#define	bytes_written(dev)		(dev).bytes[DEVSTAT_WRITE]
+#endif
+
   statinfo diskStats;
   bzero(&diskStats, sizeof(diskStats));
   diskStats.dinfo = (struct devinfo *)malloc(sizeof(struct devinfo));
@@ -258,11 +273,11 @@
   long generation;
   device_selection *deviceSelect = 0;
 
-  if (getdevs(&diskStats) < 0)
+  if (devstat_getdevs(NULL, &diskStats) < 0)
     return;
 
   deviceAmount = diskStats.dinfo->numdevs;
-  if (selectdevs(&deviceSelect, &selected, &selections,
+  if (devstat_selectdevs(&deviceSelect, &selected, &selections,
      &generation, diskStats.dinfo->generation,
      diskStats.dinfo->devices, deviceAmount,
      0, 0, 0, 0, DS_SELECT_ONLY, 10, 1) < 0)
@@ -275,8 +290,8 @@
     disk = deviceSelect[i].position;
     device = diskStats.dinfo->devices[disk];
     blockSize = (device.block_size <= 0 ? 512 : device.block_size);
-    readBlocks = device.bytes_read / blockSize;
-    writeBlocks = device.bytes_written / blockSize;
+    readBlocks = bytes_read(device) / blockSize;
+    writeBlocks = bytes_written(device) / blockSize;
 
     DiskData diskData;
     diskData.name = device.device_name
