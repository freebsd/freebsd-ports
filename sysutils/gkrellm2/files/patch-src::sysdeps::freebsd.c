Index: src/sysdeps/freebsd.c
diff -u src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	Wed Mar  5 13:14:38 2003
+++ src/sysdeps/freebsd.c	Sat Mar 22 13:58:33 2003
@@ -372,6 +372,13 @@
 
 #else
 
+#if __FreeBSD_version >= 500107
+#define getdevs(stats)	devstat_getdevs(NULL, stats)
+#define selectdevs	devstat_selectdevs
+#define bytes_read	bytes[DEVSTAT_READ]
+#define bytes_written	bytes[DEVSTAT_WRITE]
+#endif
+
 gint
 gkrellm_sys_disk_order_from_name(gchar *name)
 	{
