--- agent/mibgroup/host/hr_disk.c.orig	Sat Apr 20 16:30:03 2002
+++ agent/mibgroup/host/hr_disk.c	Wed Apr 24 01:33:15 2002
@@ -185,6 +185,9 @@
                       "/dev/rdsk/c%dt%dd0s0", 0, 7);
     Add_HR_Disk_entry("/dev/rdsk/c%dd%ds%d", 0, 1, 0, 15,
                       "/dev/rdsk/c%dd%ds0", 0, 7);
+#elif defined(__FreeBSD__) && __FreeBSD__ >= 4
+    Add_HR_Disk_entry("/dev/ad%ds%d%c", 0, 1, 1, 4, "/dev/ad%ds%d", 'a', 'h');
+    Add_HR_Disk_entry("/dev/da%ds%d%c", 0, 1, 1, 4, "/dev/da%ds%d", 'a', 'h');
 #elif defined(freebsd3)
     Add_HR_Disk_entry("/dev/wd%ds%d%c", 0, 1, 1, 4, "/dev/wd%ds%d", 'a',
                       'h');
