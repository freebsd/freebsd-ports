
$FreeBSD$

--- gmond/key_metrics.h.orig	Mon Oct 27 16:47:42 2003
+++ gmond/key_metrics.h	Mon Oct 27 16:48:12 2003
@@ -69,6 +69,15 @@
    cpu_avm,
    cpu_vm,
 #endif
+#ifdef FREEBSD
+   bytes_in,
+   bytes_out,
+   pkts_in,
+   pkts_out,
+   disk_total,
+   disk_free,
+   part_max_used,
+#endif
    num_key_metrics
 }  key_metrics;
 #endif
