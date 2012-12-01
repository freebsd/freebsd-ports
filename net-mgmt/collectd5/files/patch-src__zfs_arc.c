--- src/zfs_arc.c.orig	2012-04-02 08:04:58.000000000 +0000
+++ src/zfs_arc.c	2012-11-24 17:54:21.715129054 +0000
@@ -25,11 +25,57 @@
 #include "common.h"
 #include "plugin.h"
 
+#if !defined(HAVE_LIBKSTAT) && defined(HAVE_SYSCTLBYNAME)
+#include <sys/sysctl.h>
+#endif
+
 /*
  * Global variables
  */
-static kstat_t *ksp;
+#if defined(HAVE_LIBKSTAT)
 extern kstat_ctl_t *kc;
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
@@ -54,13 +100,13 @@
 	za_submit (type, type_instance, &vv, 1);
 }
 
-static int za_read_derive (kstat_t *ksp, const char *kstat_value,
+static int za_read_derive (struct za_context *ctx, const char *kstat_value,
     const char *type, const char *type_instance)
 {
   long long tmp;
   value_t v;
 
-  tmp = get_kstat_value (ksp, kstat_value);
+  tmp = za_get_value (ctx, (char *)kstat_value);
   if (tmp == -1LL)
   {
     ERROR ("zfs_arc plugin: Reading kstat value \"%s\" failed.", kstat_value);
@@ -69,15 +115,16 @@
 
   v.derive = (derive_t) tmp;
   za_submit (type, type_instance, /* values = */ &v, /* values_num = */ 1);
+  return (0);
 }
 
-static int za_read_gauge (kstat_t *ksp, const char *kstat_value,
+static int za_read_gauge (struct za_context *ctx, const char *kstat_value,
     const char *type, const char *type_instance)
 {
   long long tmp;
   value_t v;
 
-  tmp = get_kstat_value (ksp, kstat_value);
+  tmp = za_get_value (ctx, (char *)kstat_value);
   if (tmp == -1LL)
   {
     ERROR ("zfs_arc plugin: Reading kstat value \"%s\" failed.", kstat_value);
@@ -86,18 +133,14 @@
 
   v.gauge = (gauge_t) tmp;
   za_submit (type, type_instance, /* values = */ &v, /* values_num = */ 1);
+  return (0);
 }
 
-static void za_submit_ratio (const char* type_instance, gauge_t hits, gauge_t misses)
+static void za_submit_ratio (const char* type_instance, long long hits, long long misses)
 {
 	gauge_t ratio = NAN;
 
-	if (!isfinite (hits) || (hits < 0.0))
-		hits = 0.0;
-	if (!isfinite (misses) || (misses < 0.0))
-		misses = 0.0;
-
-	if ((hits != 0.0) || (misses != 0.0))
+	if ((hits > 0) || (misses > 0))
 		ratio = hits / (hits + misses);
 
 	za_submit_gauge ("cache_ratio", type_instance, ratio);
@@ -105,56 +148,55 @@
 
 static int za_read (void)
 {
-	gauge_t  arc_hits, arc_misses, l2_hits, l2_misses;
+	long long  arc_hits, arc_misses, l2_hits, l2_misses;
 	value_t  l2_io[2];
+	struct za_context ctx;
 
-	get_kstat (&ksp, "zfs", 0, "arcstats");
-	if (ksp == NULL)
+	if (za_init_context (&ctx) < 0)
 	{
-		ERROR ("zfs_arc plugin: Cannot find zfs:0:arcstats kstat.");
 		return (-1);
 	}
 
 	/* Sizes */
-	za_read_gauge (ksp, "size",    "cache_size", "arc");
-	za_read_gauge (ksp, "l2_size", "cache_size", "L2");
+	za_read_gauge (&ctx, "size",    "cache_size", "arc");
+	za_read_gauge (&ctx, "l2_size", "cache_size", "L2");
 
-        /* Operations */
-	za_read_derive (ksp, "allocated","cache_operation", "allocated");
-	za_read_derive (ksp, "deleted",  "cache_operation", "deleted");
-	za_read_derive (ksp, "stolen",   "cache_operation", "stolen");
-
-        /* Issue indicators */
-        za_read_derive (ksp, "mutex_miss", "mutex_operation", "miss");
-	za_read_derive (ksp, "hash_collisions", "hash_collisions", "");
+	/* Operations */
+	za_read_derive (&ctx, "allocated","cache_operation", "allocated");
+	za_read_derive (&ctx, "deleted",  "cache_operation", "deleted");
+	za_read_derive (&ctx, "stolen",   "cache_operation", "stolen");
+
+	/* Issue indicators */
+	za_read_derive (&ctx, "mutex_miss", "mutex_operation", "miss");
+	za_read_derive (&ctx, "hash_collisions", "hash_collisions", "");
 	
-        /* Evictions */
-	za_read_derive (ksp, "evict_l2_cached",     "cache_eviction", "cached");
-	za_read_derive (ksp, "evict_l2_eligible",   "cache_eviction", "eligible");
-	za_read_derive (ksp, "evict_l2_ineligible", "cache_eviction", "ineligible");
+	/* Evictions */
+	za_read_derive (&ctx, "evict_l2_cached",     "cache_eviction", "cached");
+	za_read_derive (&ctx, "evict_l2_eligible",   "cache_eviction", "eligible");
+	za_read_derive (&ctx, "evict_l2_ineligible", "cache_eviction", "ineligible");
 
 	/* Hits / misses */
-	za_read_derive (ksp, "demand_data_hits",         "cache_result", "demand_data-hit");
-	za_read_derive (ksp, "demand_metadata_hits",     "cache_result", "demand_metadata-hit");
-	za_read_derive (ksp, "prefetch_data_hits",       "cache_result", "prefetch_data-hit");
-	za_read_derive (ksp, "prefetch_metadata_hits",   "cache_result", "prefetch_metadata-hit");
-	za_read_derive (ksp, "demand_data_misses",       "cache_result", "demand_data-miss");
-	za_read_derive (ksp, "demand_metadata_misses",   "cache_result", "demand_metadata-miss");
-	za_read_derive (ksp, "prefetch_data_misses",     "cache_result", "prefetch_data-miss");
-	za_read_derive (ksp, "prefetch_metadata_misses", "cache_result", "prefetch_metadata-miss");
+	za_read_derive (&ctx, "demand_data_hits",         "cache_result", "demand_data-hit");
+	za_read_derive (&ctx, "demand_metadata_hits",     "cache_result", "demand_metadata-hit");
+	za_read_derive (&ctx, "prefetch_data_hits",       "cache_result", "prefetch_data-hit");
+	za_read_derive (&ctx, "prefetch_metadata_hits",   "cache_result", "prefetch_metadata-hit");
+	za_read_derive (&ctx, "demand_data_misses",       "cache_result", "demand_data-miss");
+	za_read_derive (&ctx, "demand_metadata_misses",   "cache_result", "demand_metadata-miss");
+	za_read_derive (&ctx, "prefetch_data_misses",     "cache_result", "prefetch_data-miss");
+	za_read_derive (&ctx, "prefetch_metadata_misses", "cache_result", "prefetch_metadata-miss");
 
 	/* Ratios */
-	arc_hits   = (gauge_t) get_kstat_value(ksp, "hits");
-	arc_misses = (gauge_t) get_kstat_value(ksp, "misses");
-	l2_hits    = (gauge_t) get_kstat_value(ksp, "l2_hits");
-	l2_misses  = (gauge_t) get_kstat_value(ksp, "l2_misses");
+	arc_hits   = za_get_value (&ctx, "hits");
+	arc_misses = za_get_value (&ctx, "misses");
+	l2_hits    = za_get_value (&ctx, "l2_hits");
+	l2_misses  = za_get_value (&ctx, "l2_misses");
 
 	za_submit_ratio ("arc", arc_hits, arc_misses);
 	za_submit_ratio ("L2", l2_hits, l2_misses);
 
 	/* I/O */
-	l2_io[0].derive = get_kstat_value(ksp, "l2_read_bytes");
-	l2_io[1].derive = get_kstat_value(ksp, "l2_write_bytes");
+	l2_io[0].derive = za_get_value (&ctx, "l2_read_bytes");
+	l2_io[1].derive = za_get_value (&ctx, "l2_write_bytes");
 
 	za_submit ("io_octets", "L2", l2_io, /* num values = */ 2);
 
@@ -163,14 +205,23 @@
 
 static int za_init (void) /* {{{ */
 {
-	ksp = NULL;
-
+#if defined(HAVE_LIBKSTAT)
 	/* kstats chain already opened by update_kstat (using *kc), verify everything went fine. */
 	if (kc == NULL)
 	{
 		ERROR ("zfs_arc plugin: kstat chain control structure not available.");
 		return (-1);
 	}
+#elif defined(HAVE_SYSCTLBYNAME)
+	/* make sure ARC is available (arc_size is not null) */
+	unsigned long long arc_size;
+	size_t size = sizeof(arc_size);
+	if (sysctlbyname("kstat.zfs.misc.arcstats.size", &arc_size, &size, NULL, 0) != 0 || arc_size == 0)
+	{
+		ERROR ("zfs_arc plugin: could not get ARC size using sysctl, is ARC enabled?");
+		return (-1);
+	}
+#endif
 
 	return (0);
 } /* }}} int za_init */
