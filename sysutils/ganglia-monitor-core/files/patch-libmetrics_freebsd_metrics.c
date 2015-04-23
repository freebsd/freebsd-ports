--- libmetrics/freebsd/metrics.c.orig	2013-05-07 09:39:40.000000000 -0500
+++ libmetrics/freebsd/metrics.c	2014-10-14 15:32:43.000000000 -0500
@@ -461,6 +461,17 @@
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
