--- src/zfs_arc.c.orig	2012-11-11 11:43:05.000000000 +0100
+++ src/zfs_arc.c	2013-02-26 15:29:15.297851681 +0100
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
@@ -46,112 +93,136 @@
 
 static void za_submit_gauge (const char* type, const char* type_instance, gauge_t value)
 {
-	value_t values[1];
+	value_t vv;
 
-	values[0].gauge = value;
+	vv.gauge = value;
 
-	za_submit (type, type_instance, values, STATIC_ARRAY_SIZE(values));
+	za_submit (type, type_instance, &vv, 1);
 }
 
-static void za_submit_size (gauge_t size, gauge_t size_target, gauge_t limit_min, gauge_t limit_max)
+static int za_read_derive (struct za_context *ctx, const char *kstat_value,
+   const char *type, const char *type_instance)
 {
-	value_t values[4];
+   long long tmp;
+   value_t v;
 
-	values[0].gauge = size;
-	values[1].gauge = size_target;
-	values[2].gauge = limit_min;
-	values[3].gauge = limit_max;
+   tmp = za_get_value (ctx, (char *)kstat_value);
+   if (tmp == -1LL)
+   {
+     ERROR ("zfs_arc plugin: Reading kstat value \"%s\" failed.", kstat_value);
+     return (-1);
+   }
 
-	za_submit ("arc_size", "", values, STATIC_ARRAY_SIZE(values));
+   v.derive = (derive_t) tmp;
+   za_submit (type, type_instance, /* values = */ &v, /* values_num = */ 1);
+   return (0);
 }
 
-static void za_submit_bytes (counter_t read, counter_t write)
+static int za_read_gauge (struct za_context *ctx, const char *kstat_value,
+	const char *type, const char *type_instance)
 {
-	value_t values[2];
+   long long tmp;
+   value_t v;
 
-	values[0].counter = read;
-	values[1].counter = write;
+   tmp = za_get_value (ctx, (char *)kstat_value);
+   if (tmp == -1LL)
+   {
+     ERROR ("zfs_arc plugin: Reading kstat value \"%s\" failed.", kstat_value);
+     return (-1);
+   }
 
-	za_submit ("arc_l2_bytes", "", values, STATIC_ARRAY_SIZE(values));
+   v.gauge = (gauge_t) tmp;
+   za_submit (type, type_instance, /* values = */ &v, /* values_num = */ 1);
+   return (0);
 }
 
-static void za_submit_counts (char *type_instance, counter_t demand_data, counter_t demand_metadata,
-	counter_t prefetch_data, counter_t prefetch_metadata)
+static void za_submit_ratio (const char* type_instance, long long hits, long long misses)
 {
-	value_t values[4];
+	gauge_t ratio = NAN;
 
-	values[0].counter = demand_data;
-	values[1].counter = demand_metadata;
-	values[2].counter = prefetch_data;
-	values[3].counter = prefetch_metadata;
+	if ((hits > 0) || (misses > 0))
+		ratio = hits / (hits + misses);
 
-	za_submit ("arc_counts", type_instance, values, STATIC_ARRAY_SIZE(values));
+	za_submit_gauge ("cache_ratio", type_instance, ratio);
 }
 
 static int za_read (void)
 {
-	gauge_t   arcsize, targetsize, minlimit, maxlimit, hits, misses, l2_size, l2_hits, l2_misses;
-	counter_t demand_data_hits, demand_metadata_hits, prefetch_data_hits, prefetch_metadata_hits;
-	counter_t demand_data_misses, demand_metadata_misses, prefetch_data_misses, prefetch_metadata_misses;
-	counter_t l2_read_bytes, l2_write_bytes;
-	kstat_t	 *ksp	= NULL;
+	long long l2_read_bytes, l2_write_bytes;
+	long long  arc_hits, arc_misses, l2_hits, l2_misses;
+	value_t  l2_io[2];
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
-
-
-	za_submit_size (arcsize, targetsize, minlimit, maxlimit);
-	za_submit_gauge ("arc_l2_size", "", l2_size);
-
-	za_submit_counts ("hits",   demand_data_hits,     demand_metadata_hits,
-	                            prefetch_data_hits,   prefetch_metadata_hits);
-	za_submit_counts ("misses", demand_data_misses,   demand_metadata_misses,
-	                            prefetch_data_misses, prefetch_metadata_misses);
+	/* Sizes */
+	za_read_gauge (&ctx, "size",    "cache_size", "arc");
+	za_read_gauge (&ctx, "l2_size", "cache_size", "L2");
+
+	/* Operations */
+	za_read_derive (&ctx, "allocated","cache_operation", "allocated");
+	za_read_derive (&ctx, "deleted",  "cache_operation", "deleted");
+	za_read_derive (&ctx, "stolen",   "cache_operation", "stolen");
+
+	/* Issue indicators */
+	za_read_derive (&ctx, "mutex_miss", "mutex_operation", "miss");
+	za_read_derive (&ctx, "hash_collisions", "hash_collisions", "");
+
+	/* Evictions */
+	za_read_derive (&ctx, "evict_l2_cached",     "cache_eviction", "cached");
+	za_read_derive (&ctx, "evict_l2_eligible",   "cache_eviction", "eligible");
+	za_read_derive (&ctx, "evict_l2_ineligible", "cache_eviction", "ineligible");
+
+	/* Hits / misses */
+	za_read_derive (&ctx, "demand_data_hits",         "cache_result", "demand_data-hit");
+	za_read_derive (&ctx, "demand_metadata_hits",     "cache_result", "demand_metadata-hit");
+	za_read_derive (&ctx, "prefetch_data_hits",       "cache_result", "prefetch_data-hit");
+	za_read_derive (&ctx, "prefetch_metadata_hits",   "cache_result", "prefetch_metadata-hit");
+	za_read_derive (&ctx, "demand_data_misses",       "cache_result", "demand_data-miss");
+	za_read_derive (&ctx, "demand_metadata_misses",   "cache_result", "demand_metadata-miss");
+	za_read_derive (&ctx, "prefetch_data_misses",     "cache_result", "prefetch_data-miss");
+	za_read_derive (&ctx, "prefetch_metadata_misses", "cache_result", "prefetch_metadata-miss");
+
+	/* Ratios */
+	arc_hits   = za_get_value (&ctx, "hits");
+	arc_misses = za_get_value (&ctx, "misses");
+	l2_hits    = za_get_value (&ctx, "l2_hits");
+	l2_misses  = za_get_value (&ctx, "l2_misses");
+
+	za_submit_ratio ("arc", arc_hits, arc_misses);
+	za_submit_ratio ("L2", l2_hits, l2_misses);
+
+	/* I/O */
+	l2_io[0].derive = za_get_value (&ctx, "l2_read_bytes");
+	l2_io[1].derive = za_get_value (&ctx, "l2_write_bytes");
 
-	za_submit_gauge ("arc_ratio", "L1", hits / (hits + misses));
-	za_submit_gauge ("arc_ratio", "L2", l2_hits / (l2_hits + l2_misses));
-
-	za_submit_bytes (l2_read_bytes, l2_write_bytes);
+	za_submit ("io_octets", "L2", l2_io, /* num values = */ 2);
 
 	return (0);
-}
+} /* int za_read */
 
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
