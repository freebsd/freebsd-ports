Index: src/sysdeps/freebsd.c
diff -u src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	Tue Jan 21 02:35:11 2003
+++ src/sysdeps/freebsd.c	Tue Jan 21 02:35:22 2003
@@ -918,6 +918,10 @@
 #define	PROC_MEMINFO_FILE	"/compat/linux/proc/meminfo"
 #endif
 
+#ifndef VM_TOTAL
+#define VM_TOTAL	VM_METER
+#endif
+
 static guint64	swapin,
 		swapout,
 		swap_total,
@@ -935,7 +939,7 @@
 	guint64		total, used, x_used, free, shared, buffers, cached;
 	struct vmtotal	vmt;
 	size_t		length_vmt = sizeof(vmt);
-	static int	oid_vmt[] = { CTL_VM, VM_METER };
+	static int	oid_vmt[] = { CTL_VM, VM_TOTAL };
 #if __FreeBSD_version >= 410000
 	gint		i;
 	FILE		*f;
