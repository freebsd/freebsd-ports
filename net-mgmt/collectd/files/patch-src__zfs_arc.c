--- src/zfs_arc.c.orig	2012-11-11 11:43:05.000000000 +0100
+++ src/zfs_arc.c	2012-12-31 00:59:33.000000000 +0100
@@ -23,11 +23,58 @@
 #include "common.h"
 #include "plugin.h"
 
+#if !defined(HAVE_LIBKSTAT) && defined(HAVE_SYSCTLBYNAME)
+#include <sys/sysctl.h>
+#endif
+
 /*
  * Global variables
  */
 
-extern kstat_ctl_t *kc;
+#if defined(HAVE_LIBKSTAT)
+ extern kstat_ctl_t *kc;
+#endif
+
+/*
+ * Context
+ */
+struct za_context {
+#if defined(HAVE_LIBKSTAT)
+    kstat_t *ksp;
+#endif
+};
+
+static int za_init_context(struct za_context *ctx)
+{
+#if defined(HAVE_LIBKSTAT)
+	get_kstat (&ctx->ksp, "zfs", 0, "arcstats");
+	if (ctx->ksp == NULL)
+	{
+		ERROR ("zfs_arc plugin: Cannot find zfs:0:arcstats kstat.");
+		return (-1);
+	}
+#endif
+	return 0;
+}
+
+static long long za_get_value(struct za_context *ctx, const char* name)
+{
+#if defined(HAVE_LIBKSTAT)
+	return get_kstat_value(ctx->ksp, name);
+#elif defined(HAVE_SYSCTLBYNAME)
+	// kstat values are available on FreeBSD through sysctl
+	char fullname[512];
+	long long result = 0;
+	size_t size = sizeof(result);
+	ssnprintf(fullname, sizeof(fullname), "kstat.zfs.misc.arcstats.%s", name);
+	if (sysctlbyname(fullname, &result, &size, NULL, 0) != 0 || size != sizeof(result))
+	{
+		ERROR ("zfs_arc plugin: Cannot find stats using sysctl");
+		result = 0;
+	}
+	return result;
+#endif
+}
 
 static void za_submit (const char* type, const char* type_instance, value_t* values, int values_len)
 {
@@ -90,42 +137,40 @@
 
 static int za_read (void)
 {
-	gauge_t   arcsize, targetsize, minlimit, maxlimit, hits, misses, l2_size, l2_hits, l2_misses;
-	counter_t demand_data_hits, demand_metadata_hits, prefetch_data_hits, prefetch_metadata_hits;
-	counter_t demand_data_misses, demand_metadata_misses, prefetch_data_misses, prefetch_metadata_misses;
-	counter_t l2_read_bytes, l2_write_bytes;
-	kstat_t	 *ksp	= NULL;
+	long long   arcsize, targetsize, minlimit, maxlimit, hits, misses, l2_size, l2_hits, l2_misses;
+	long long demand_data_hits, demand_metadata_hits, prefetch_data_hits, prefetch_metadata_hits;
+	long long demand_data_misses, demand_metadata_misses, prefetch_data_misses, prefetch_metadata_misses;
+	long long l2_read_bytes, l2_write_bytes;
+	struct za_context ctx;
 
-	get_kstat (&ksp, "zfs", 0, "arcstats");
-	if (ksp == NULL)
+	if (za_init_context (&ctx) < 0)
 	{
-		ERROR ("zfs_arc plugin: Cannot find zfs:0:arcstats kstat.");
 		return (-1);
 	}
 
-	arcsize    = get_kstat_value(ksp, "size");
-	targetsize = get_kstat_value(ksp, "c");
-	minlimit   = get_kstat_value(ksp, "c_min");
-	maxlimit   = get_kstat_value(ksp, "c_max");
-
-	demand_data_hits       = get_kstat_value(ksp, "demand_data_hits");
-	demand_metadata_hits   = get_kstat_value(ksp, "demand_metadata_hits");
-	prefetch_data_hits     = get_kstat_value(ksp, "prefetch_data_hits");
-	prefetch_metadata_hits = get_kstat_value(ksp, "prefetch_metadata_hits");
-
-	demand_data_misses       = get_kstat_value(ksp, "demand_data_misses");
-	demand_metadata_misses   = get_kstat_value(ksp, "demand_metadata_misses");
-	prefetch_data_misses     = get_kstat_value(ksp, "prefetch_data_misses");
-	prefetch_metadata_misses = get_kstat_value(ksp, "prefetch_metadata_misses");
-
-	hits   = get_kstat_value(ksp, "hits");
-	misses = get_kstat_value(ksp, "misses");
-
-	l2_size        = get_kstat_value(ksp, "l2_size");
-	l2_read_bytes  = get_kstat_value(ksp, "l2_read_bytes");
-	l2_write_bytes = get_kstat_value(ksp, "l2_write_bytes");
-	l2_hits        = get_kstat_value(ksp, "l2_hits");
-	l2_misses      = get_kstat_value(ksp, "l2_misses");
+	arcsize    = za_get_value(&ctx, "size");
+	targetsize = za_get_value(&ctx, "c");
+	minlimit   = za_get_value(&ctx, "c_min");
+	maxlimit   = za_get_value(&ctx, "c_max");
+
+	demand_data_hits       = za_get_value(&ctx, "demand_data_hits");
+	demand_metadata_hits   = za_get_value(&ctx, "demand_metadata_hits");
+	prefetch_data_hits     = za_get_value(&ctx, "prefetch_data_hits");
+	prefetch_metadata_hits = za_get_value(&ctx, "prefetch_metadata_hits");
+
+	demand_data_misses       = za_get_value(&ctx, "demand_data_misses");
+	demand_metadata_misses   = za_get_value(&ctx, "demand_metadata_misses");
+	prefetch_data_misses     = za_get_value(&ctx, "prefetch_data_misses");
+	prefetch_metadata_misses = za_get_value(&ctx, "prefetch_metadata_misses");
+
+	hits   = za_get_value(&ctx, "hits");
+	misses = za_get_value(&ctx, "misses");
+
+	l2_size        = za_get_value(&ctx, "l2_size");
+	l2_read_bytes  = za_get_value(&ctx, "l2_read_bytes");
+	l2_write_bytes = za_get_value(&ctx, "l2_write_bytes");
+	l2_hits        = za_get_value(&ctx, "l2_hits");
+	l2_misses      = za_get_value(&ctx, "l2_misses");
 
 
 	za_submit_size (arcsize, targetsize, minlimit, maxlimit);
@@ -146,12 +191,23 @@
 
 static int za_init (void) /* {{{ */
 {
-	/* kstats chain already opened by update_kstat (using *kc), verify everything went fine. */
-	if (kc == NULL)
+#if defined(HAVE_LIBKSTAT)
+ 	/* kstats chain already opened by update_kstat (using *kc), verify everything went fine. */
+ 	if (kc == NULL)
+ 	{
+ 		ERROR ("zfs_arc plugin: kstat chain control structure not available.");
+ 		return (-1);
+ 	}
+#elif defined(HAVE_SYSCTLBYNAME)
+	/* make sure ARC is available (arc_size is not null) */
+	unsigned long long arc_size;
+	size_t size = sizeof(arc_size);
+	if (sysctlbyname("kstat.zfs.misc.arcstats.size", &arc_size, &size, NULL, 0) != 0 || arc_size == 0)
 	{
-		ERROR ("zfs_arc plugin: kstat chain control structure not available.");
+		ERROR ("zfs_arc plugin: could not get ARC size using sysctl, is ARC enabled?");
 		return (-1);
 	}
+#endif
 
 	return (0);
 } /* }}} int za_init */
