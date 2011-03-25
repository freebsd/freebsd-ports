--- FreeBSD/diskstat.c	2011-03-17 20:50:04.000000000 +0200
+++ FreeBSD/diskstat.c	2011-02-19 23:24:28.000000000 +0200
@@ -19,8 +19,6 @@
 
 */
 
-#include <config-workspace.h>
-
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -43,8 +41,19 @@
 	long bfree;
 	long bused;
 	int bused_percent;
+	long bsize;
+	long files;
+	long ffree;
+	long fused;
+	int fused_percent;
 } DiskInfo;
 
+#define BLK2KB(disk_info, prop)						\
+	(disk_info->prop * (disk_info->bsize / 1024))
+
+#define MNTPNT_NAME(disk_info)						\
+	(strcmp(disk_info->mntpnt, "/root") ? disk_info->mntpnt : "/")
+
 static CONTAINER DiskStatList = 0;
 static struct SensorModul* DiskStatSM;
 
@@ -96,6 +105,12 @@
 		registerMonitor(monitor, "integer", printDiskStatFree, printDiskStatFreeInfo, DiskStatSM);
 		snprintf(monitor, sizeof(monitor), "partitions%s/filllevel", disk_info->mntpnt);
 		registerMonitor(monitor, "integer", printDiskStatPercent, printDiskStatPercentInfo, DiskStatSM);
+		snprintf(monitor, sizeof(monitor), "partitions%s/usedinode", disk_info->mntpnt);
+		registerMonitor(monitor, "integer", printDiskStatIUsed, printDiskStatIUsedInfo, DiskStatSM);
+		snprintf(monitor, sizeof(monitor), "partitions%s/freeinode", disk_info->mntpnt);
+		registerMonitor(monitor, "integer", printDiskStatIFree, printDiskStatIFreeInfo, DiskStatSM);
+		snprintf(monitor, sizeof(monitor), "partitions%s/inodelevel", disk_info->mntpnt);
+		registerMonitor(monitor, "integer", printDiskStatIPercent, printDiskStatIPercentInfo, DiskStatSM);
 	}
 }
 
@@ -123,6 +138,12 @@
 		removeMonitor(monitor);
 		snprintf(monitor, sizeof(monitor), "partitions%s/filllevel", disk_info->mntpnt);
 		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "partitions%s/usedinode", disk_info->mntpnt);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "partitions%s/freeinode", disk_info->mntpnt);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "partitions%s/inodelevel", disk_info->mntpnt);
+		removeMonitor(monitor);
 	}
 
 	destr_ctnr(DiskStatList, free);
@@ -132,7 +153,7 @@
 {
 	struct statfs *fs_info;
 	struct statfs fs;
-	float percent;
+	float percent, fpercent;
 	int i, mntcount;
 	DiskInfo *disk_info;
 
@@ -144,29 +165,33 @@
 
 	for (i = 0; i < mntcount; i++) {
 		fs = fs_info[i];
-		if (strcmp(fs.f_fstypename, "procfs") && strcmp(fs.f_fstypename, "devfs") && strcmp(fs.f_fstypename, "devfs")) {
+		if (strcmp(fs.f_fstypename, "procfs") && strcmp(fs.f_fstypename, "devfs") && strcmp(fs.f_fstypename, "linprocfs")) {
 			if ( fs.f_blocks != 0 )
-			{
-					percent = (((float)fs.f_blocks - (float)fs.f_bfree)*100.0/(float)fs.f_blocks);
-			}
+				percent = (((float)fs.f_blocks - (float)fs.f_bfree)*100.0/(float)fs.f_blocks);
 			else
-			  percent = 0;
-			if ((disk_info = (DiskInfo *)malloc(sizeof(DiskInfo))) == NULL) {
+				percent = 0;
+			if (fs.f_files != 0)
+				fpercent = (((float)fs.f_files - (float)fs.f_ffree)*100.0/(float)fs.f_files);
+			else
+				fpercent = 0;
+			if ((disk_info = (DiskInfo *)malloc(sizeof(DiskInfo))) == NULL)
 				continue;
-			}
 			memset(disk_info, 0, sizeof(DiskInfo));
 			strlcpy(disk_info->device, fs.f_mntfromname, sizeof(disk_info->device));
-			if (!strcmp(fs.f_mntonname, "/")) {
+			if (!strcmp(fs.f_mntonname, "/"))
 				strncpy(disk_info->mntpnt, "/root", 6);
-			} else {
+			else
 				strlcpy(disk_info->mntpnt, fs.f_mntonname, sizeof(disk_info->mntpnt));
-			}
 			disk_info->blocks = fs.f_blocks;
 			disk_info->bfree = fs.f_bfree;
 			disk_info->bused = (fs.f_blocks - fs.f_bfree);
 			disk_info->bused_percent = (int)percent;
-
+			disk_info->bsize = fs.f_bsize;
 			push_ctnr(DiskStatList, disk_info);
+			disk_info->files = fs.f_files;
+			disk_info->ffree = fs.f_ffree;
+			disk_info->fused = fs.f_files - fs.f_ffree;
+			disk_info->fused_percent = (int)fpercent;
 		}
 	}
 
@@ -178,13 +203,17 @@
 	DiskInfo* disk_info;
 
 	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
-		fprintf(CurrentClient, "%s\t%ld\t%ld\t%ld\t%d\t%s\n",
+		fprintf(CurrentClient, "%s\t%ld\t%ld\t%ld\t%d\t%ld\t%ld\t%ld\t%d\t%s\n",
 			disk_info->device,
-			disk_info->blocks,
-			disk_info->bused,
-			disk_info->bfree,
+			BLK2KB(disk_info, blocks),
+			BLK2KB(disk_info, bused),
+			BLK2KB(disk_info, bfree),
 			disk_info->bused_percent,
-			disk_info->mntpnt);
+			disk_info->files,
+			disk_info->fused,
+			disk_info->ffree,
+			disk_info->fused_percent,
+			MNTPNT_NAME(disk_info));
 	}
 
 	fprintf(CurrentClient, "\n");
@@ -192,7 +221,7 @@
 
 void printDiskStatInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "Device\tBlocks\tUsed\tAvailable\tUsed %%\tMountPoint\nM\tD\tD\tD\td\ts\n");
+	fprintf(CurrentClient, "Device\tCapacity\tUsed\tAvailable\tUsed %%\tInodes\tUsed Inodes\tFree Inodes\tInodes %%\tMountPoint\nM\tKB\tKB\tKB\td\td\td\td\td\ts\n");
 }
 
 void printDiskStatUsed(const char* cmd)
@@ -202,7 +231,8 @@
 
 	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
 		if (!strcmp(mntpnt, disk_info->mntpnt)) {
-			fprintf(CurrentClient, "%ld\n", disk_info->bused);
+			fprintf(CurrentClient, "%ld\n", BLK2KB(disk_info, bused));
+			return;
 		}
 	}
 
@@ -211,7 +241,16 @@
 
 void printDiskStatUsedInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "Used Blocks\t0\t-\tBlocks\n");
+	DiskInfo* disk_info;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "Used Space (%s)\t0\t%ld\tKB\n", MNTPNT_NAME(disk_info), BLK2KB(disk_info, blocks));
+			return;
+		}
+	}
+	fprintf(CurrentClient, "Used Space (%s)\t0\t-\tKB\n", mntpnt);
 }
 
 void printDiskStatFree(const char* cmd)
@@ -221,7 +260,8 @@
 
 	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
 		if (!strcmp(mntpnt, disk_info->mntpnt)) {
-			fprintf(CurrentClient, "%ld\n", disk_info->bfree);
+			fprintf(CurrentClient, "%ld\n", BLK2KB(disk_info, bfree));
+			return;
 		}
 	}
 
@@ -230,7 +270,16 @@
 
 void printDiskStatFreeInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "Free Blocks\t0\t-\tBlocks\n");
+	DiskInfo* disk_info;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "Free Space (%s)\t0\t%ld\tKB\n", MNTPNT_NAME(disk_info), BLK2KB(disk_info, blocks));
+			return;
+		}
+	}
+	fprintf(CurrentClient, "Free Space (%s)\t0\t-\tKB\n", mntpnt);
 }
 
 void printDiskStatPercent(const char* cmd)
@@ -241,6 +290,7 @@
 	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
 		if (!strcmp(mntpnt, disk_info->mntpnt)) {
 			fprintf(CurrentClient, "%d\n", disk_info->bused_percent);
+			return;
 		}
 	}
 
@@ -249,5 +299,88 @@
 
 void printDiskStatPercentInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "Used Blocks\t0\t100\t%%\n");
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	fprintf(CurrentClient, "Used Space (%s)\t0\t100\t%%\n", mntpnt);
+}
+
+void printDiskStatIUsed(const char* cmd)
+{
+	DiskInfo* disk_info;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "%ld\n", disk_info->fused);
+			return;
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
 }
+
+void printDiskStatIUsedInfo(const char* cmd)
+{
+	DiskInfo* disk_info;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "Used Inodes (%s)\t0\t%ld\tKB\n", MNTPNT_NAME(disk_info), disk_info->files);
+			return;
+		}
+	}
+	fprintf(CurrentClient, "Used Inodes(%s)\t0\t-\tKB\n", mntpnt);
+}
+
+void printDiskStatIFree(const char* cmd)
+{
+	DiskInfo* disk_info;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "%ld\n", disk_info->ffree);
+			return;
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printDiskStatIFreeInfo(const char* cmd)
+{
+	DiskInfo* disk_info;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "Free Inodes (%s)\t0\t%ld\tKB\n", MNTPNT_NAME(disk_info), disk_info->files);
+			return;
+		}
+	}
+	fprintf(CurrentClient, "Free Inodes (%s)\t0\t-\tKB\n", mntpnt);
+}
+
+void printDiskStatIPercent(const char* cmd)
+{
+	DiskInfo* disk_info;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (disk_info = first_ctnr(DiskStatList); disk_info; disk_info = next_ctnr(DiskStatList)) {
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "%d\n", disk_info->fused_percent);
+			return;
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printDiskStatIPercentInfo(const char* cmd)
+{
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	fprintf(CurrentClient, "Used Inodes (%s)\t0\t100\t%%\n", mntpnt);
+}
+
