Index: src/meminfo.c
diff -u src/meminfo.c.orig src/meminfo.c
--- src/meminfo.c.orig	Mon Jul  1 11:20:45 2002
+++ src/meminfo.c	Tue Jan 21 02:31:51 2003
@@ -490,6 +490,10 @@
 #define	PROC_MEMINFO_FILE	"/compat/linux/proc/meminfo"
 #endif
 
+#ifndef VM_TOTAL
+#define VM_TOTAL	VM_METER
+#endif
+
 static void
 read_freebsd_meminfo()
 	{
@@ -502,7 +506,7 @@
 	unsigned long	buffers;
 	struct vmtotal	vmt;
 	size_t		length_vmt = sizeof(vmt);
-	static int	oid_vmt[] = { CTL_VM, VM_METER };
+	static int	oid_vmt[] = { CTL_VM, VM_TOTAL };
 #if __FreeBSD_version >= 410000
 	static int	oid_name2oid[2] = { 0, 3 };
 	gint		i;
