
$FreeBSD$

--- gmond/metric.h.orig	Mon Oct 27 16:47:53 2003
+++ gmond/metric.h	Mon Oct 27 16:48:15 2003
@@ -88,6 +88,18 @@
 
 #endif
 
+#ifdef FREEBSD
+
+extern g_val_t bytes_in_func(void);
+extern g_val_t bytes_out_func(void);
+extern g_val_t pkts_in_func(void);
+extern g_val_t pkts_out_func(void);
+extern g_val_t disk_total_func(void);
+extern g_val_t disk_free_func(void);
+extern g_val_t part_max_used_func(void);
+
+#endif
+
 #define INIT 0, 0, {0}, {0}
 #define KEY(NAME) { #NAME, NAME ##_func, INIT
 
@@ -182,7 +194,8 @@
 KEY(pkts_in), 256, 30,   40,  200,  300, g_float, "packets/sec", "%.2f" },
 KEY(pkts_out),   256, 30,   40,  200,  300, g_float, "packets/sec", "%.2f" },
 
-/* The amount of disk space could change - hot-swap, mounts, etc. check: 30-60min. */
+/*
+ * The amount of disk space could change - hot-swap, mounts, etc. check: 30-60min. */
 KEY(disk_total), 1, 1800, 3600, 900, 1200, g_double, "GB", "%.3f" },
 KEY(disk_free), 1, 30, 40, 120, 180, g_double, "GB", "%.3f" },
 KEY(part_max_used), 1, 30, 40, 120, 180, g_float, "%", "%.1f" }
@@ -198,6 +211,30 @@
 KEY(mem_rm),   1024,  30,   40,  120,  180, g_uint32, "KB", "%u" },
 KEY(mem_avm),   1024,  30,   40,  120,  180, g_uint32, "KB", "%u" },
 KEY(mem_vm),   1024,  30,   40,  120,  180, g_uint32, "KB", "%u" }
+
+#endif
+
+#ifdef FREEBSD
+
+,
+/*
+ * (sacerdoti) Experiments have shown gmon resting bandwidth is around
+ * 2KB/s for a 128-node cluster. We set the value thresh of these
+ * metrics to double that.
+ *
+ */
+KEY(bytes_out),  4096, 30,   40,  200,  300, g_float, "bytes/sec", "%.2f" },
+KEY(bytes_in),   4096, 30,   40,  200,  300, g_float, "bytes/sec", "%.2f" },
+KEY(pkts_in), 256, 30,   40,  200,  300, g_float, "packets/sec", "%.2f" },
+KEY(pkts_out),   256, 30,   40,  200,  300, g_float, "packets/sec", "%.2f" },
+
+/*
+ * The amount of disk space could change - hot-swap, mounts, etc.
+ * check: 30-60min.
+ */
+KEY(disk_total), 1, 1800, 3600, 900, 1200, g_double, "GB", "%.3f" },
+KEY(disk_free), 1, 30, 40, 120, 180, g_double, "GB", "%.3f" },
+KEY(part_max_used), 1, 30, 40, 120, 180, g_float, "%", "%.1f" }
 
 #endif
 };
