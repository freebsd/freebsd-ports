Index: src/disk.c
diff -u src/disk.c.orig src/disk.c
--- src/disk.c.orig	Mon Jul  1 11:19:47 2002
+++ src/disk.c	Sat Mar 22 20:03:22 2003
@@ -70,7 +70,11 @@
 
 #if defined(__FreeBSD__)
 #include <osreldate.h>
+#if __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
 #include <sys/dkstat.h>
+#endif
 #if __FreeBSD_version >= 300000
 #include <devstat.h>
 static struct statinfo	statinfo_cur;
@@ -161,6 +165,14 @@
 	using_DiskN_names = TRUE;
 	}
 #else
+#if __FreeBSD_version >= 500107
+#define getdevs(stats)	devstat_getdevs(NULL, stats)
+#define getnumdevs()	devstat_getnumdevs(NULL)
+#define selectdevs	devstat_selectdevs
+#define bytes_read	bytes[DEVSTAT_READ]
+#define bytes_written	bytes[DEVSTAT_WRITE]
+#endif
+
 static void
 read_freebsd_disk()
 	{
