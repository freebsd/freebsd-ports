--- agent/mibgroup/host/hr_disk.c.orig	Tue Feb 26 01:57:26 2002
+++ agent/mibgroup/host/hr_disk.c	Fri Mar 29 16:06:29 2002
@@ -185,7 +185,7 @@
 #elif defined(solaris2)
     Add_HR_Disk_entry ( "/dev/rdsk/c%dt%dd0s%d", 0, 1, 0, 15, "/dev/rdsk/c%dt%dd0s0", 0, 7 );
     Add_HR_Disk_entry ( "/dev/rdsk/c%dd%ds%d",   0, 1, 0, 15, "/dev/rdsk/c%dd%ds0", 0, 7 );
-#elif defined(freebsd4)
+#elif defined(__FreeBSD__) && __FreeBSD__ >= 4
     Add_HR_Disk_entry ( "/dev/ad%ds%d%c", 0, 1, 1, 4, "/dev/ad%ds%d", 'a', 'h');
     Add_HR_Disk_entry ( "/dev/da%ds%d%c", 0, 1, 1, 4, "/dev/da%ds%d", 'a', 'h');
 #elif defined(freebsd3)
