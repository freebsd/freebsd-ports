--- src/disk.c.orig	2016-01-22 09:51:17 UTC
+++ src/disk.c
@@ -53,6 +53,10 @@
 #if HAVE_IOKIT_IOBSD_H
 #  include <IOKit/IOBSD.h>
 #endif
+#if KERNEL_FREEBSD
+#include <devstat.h>
+#include <libgeom.h>
+#endif
 
 #if HAVE_LIMITS_H
 # include <limits.h>
@@ -107,6 +111,9 @@ typedef struct diskstats
 
 static diskstats_t *disklist;
 /* #endif KERNEL_LINUX */
+#elif KERNEL_FREEBSD
+static struct gmesh geom_tree;
+/* #endif KERNEL_FREEBSD */
 
 #elif HAVE_LIBKSTAT
 #define MAX_NUMDISK 1024
@@ -222,6 +229,21 @@ static int disk_init (void)
 	/* do nothing */
 /* #endif KERNEL_LINUX */
 
+#elif KERNEL_FREEBSD
+	int rv;
+
+	rv = geom_gettree(&geom_tree);
+	if (rv != 0) {
+		ERROR ("geom_gettree() failed, returned %d", rv);
+		return (-1);
+	}
+	rv = geom_stats_open();
+	if (rv != 0) {
+		ERROR ("geom_stats_open() failed, returned %d", rv);
+		return (-1);
+	}
+/* #endif KERNEL_FREEBSD */
+
 #elif HAVE_LIBKSTAT
 	kstat_t *ksp_chain;
 
