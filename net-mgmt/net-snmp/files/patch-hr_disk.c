--- agent/mibgroup/host/hr_disk.c.orig	Mon Nov 19 13:48:10 2001
+++ agent/mibgroup/host/hr_disk.c	Tue Feb 12 22:37:43 2002
@@ -178,6 +178,9 @@
 #elif defined(solaris2)
     Add_HR_Disk_entry ( "/dev/rdsk/c%dt%dd0s%d", 0, 1, 0, 15, "/dev/rdsk/c%dt%dd0s0", 0, 7 );
     Add_HR_Disk_entry ( "/dev/rdsk/c%dd%ds%d",   0, 1, 0, 15, "/dev/rdsk/c%dd%ds0", 0, 7 );
+#elif defined(__FreeBSD__) && __FreeBSD__ >= 4
+    Add_HR_Disk_entry ( "/dev/ad%ds%d%c", 0, 1, 1, 4, "/dev/ad%ds%d", 'a', 'h');
+    Add_HR_Disk_entry ( "/dev/da%ds%d%c", 0, 1, 1, 4, "/dev/da%ds%d", 'a', 'h');
 #elif defined(freebsd3)
     Add_HR_Disk_entry ( "/dev/wd%ds%d%c", 0, 1, 1, 4, "/dev/wd%ds%d", 'a', 'h');
     Add_HR_Disk_entry ( "/dev/sd%ds%d%c", 0, 1, 1, 4, "/dev/sd%ds%d", 'a', 'h');
