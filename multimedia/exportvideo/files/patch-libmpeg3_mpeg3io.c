--- libmpeg3/mpeg3io.c.orig	Mon Feb 12 22:35:19 2001
+++ libmpeg3/mpeg3io.c	Mon Nov  1 09:41:06 2004
@@ -1,7 +1,7 @@
 #include "mpeg3private.h"
 #include "mpeg3protos.h"
 
-#include <mntent.h>
+#include <fstab.h>
 #include <sys/stat.h>
 #include <stdlib.h>
 #include <string.h>
@@ -89,8 +89,8 @@
 int mpeg3io_device(char *path, char *device)
 {
 	struct stat file_st, device_st;
-    struct mntent *mnt;
-	FILE *fp;
+	struct fstab *mnt;
+	int fp;
 
 	if(stat(path, &file_st) < 0)
 	{
@@ -98,17 +98,17 @@
 		return 1;
 	}
 
-	fp = setmntent(MOUNTED, "r");
-    while(fp && (mnt = getmntent(fp)))
+	fp = setfsent();
+	while(fp && (mnt = getfsent()))
 	{
-		if(stat(mnt->mnt_fsname, &device_st) < 0) continue;
-		if(device_st.st_rdev == file_st.st_dev)
-		{
-			strncpy(device, mnt->mnt_fsname, MPEG3_STRLEN);
-			break;
-		}
+	  if(stat(mnt->fs_spec, &device_st) < 0) continue;
+	  if(device_st.st_rdev == file_st.st_dev)
+	    {
+	      strncpy(device, mnt->fs_spec, MPEG3_STRLEN);
+	      break;
+	    }
 	}
-	endmntent(fp);
+	endfsent();
 
 	return 0;
 }
