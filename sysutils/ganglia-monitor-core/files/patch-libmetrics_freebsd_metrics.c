--- libmetrics/freebsd/metrics.c.orig	2015-07-01 19:49:35 UTC
+++ libmetrics/freebsd/metrics.c
@@ -461,6 +461,17 @@ cpu_sintr_func ( void )
    return val;
 }
 
+/*
+** FIXME - Not yet implemented on FreeBSD.
+*/
+g_val_t
+cpu_steal_func ( void )
+{
+   g_val_t val;
+   val.f = 0.0;
+   return val;
+}
+
 g_val_t
 load_one_func ( void )
 {
