--- bbsmount.cc.orig	Thu May  8 16:10:07 2003
+++ bbsmount.cc	Sat Oct 11 08:02:39 2003
@@ -41,6 +41,9 @@
 #endif /* !TIME_WITH_SYS_TIME */
 
 #include <pthread.h>
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
 
 #include "bbsmount.hh"
 #include "version.h"
@@ -128,25 +131,18 @@
 {
     set<int> result;
     map<string, int>::const_iterator pointer;
-    char buffer[max_mtab_line_length], md[max_mount_device_point_size], mp[max_mount_device_point_size];
-    FILE *mtab;
-
-    mtab = fopen(MTAB_FILE, "rt");
-    if (!mtab) {
-	fprintf(stderr, "Can't open mtab file!");
+    struct statfs *mbuf;
+    int i, size;
+    if((size = getmntinfo(&mbuf, MNT_NOWAIT)) == 0) {
+	fprintf(stderr, "getmntinfo() failed");
 	return result;
+    } 
+
+    for(i = 0; i < size; i++) {
+	pointer = mount_points.find(string(mbuf[i].f_mntonname));
+	if (pointer != mount_points.end())
+	  result.insert(pointer->second);
     }
-    
-    while (!feof(mtab)) {
-	if (fgets(buffer, max_mtab_line_length, mtab) > 0) {
-	    sscanf(buffer, "%s %s", md, mp);
-	    pointer = mount_points.find(string(mp));
-	    if (pointer != mount_points.end())
-		result.insert(pointer->second);
-	}
-    }
-    
-    fclose(mtab);
     return result;
 }
 
@@ -179,26 +175,18 @@
 void *
 check_mounts(void *param)
 {
-    struct stat info;
-    int mtab_size = 0, return_value, counter;
-    time_t mtab_time = time(NULL);
+    int return_value, counter;
     map<string, int> mount_points;
 
     for (counter = 0; counter < (int)AppWindow->GetMountPointsCount(); counter++)
 	mount_points[AppWindow->GetMountPoint(counter).GetMountPoint()] = counter;
     while (!finish_checking) {
-	stat(MTAB_FILE, &info);
-	if ((difftime(info.st_mtime, mtab_time) > 0) || (mtab_size != info.st_size)) {
-	    mtab_size = info.st_size;
-	    mtab_time = info.st_mtime;
-	    update_mount_points(mount_points);
-	    create_notify_event();
-	}
+	update_mount_points(mount_points);
+	create_notify_event();
 	return_value = sleep(AppWindow->GetResources()->app.refresh_time);
 	if (return_value != 0)
 	    finish_checking = true;
     }
-
     pthread_exit(NULL);
     return NULL;
 }
