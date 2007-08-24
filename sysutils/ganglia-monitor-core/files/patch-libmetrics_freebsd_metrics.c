
$FreeBSD$

--- libmetrics/freebsd/metrics.c.orig
+++ libmetrics/freebsd/metrics.c
@@ -211,7 +211,7 @@
 {
    g_val_t val;
    size_t len;
-   long total;
+   u_long total;
 
    len = sizeof(total);
 
