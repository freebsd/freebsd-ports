--- rsb_util.c.orig	2015-05-01 21:21:34 UTC
+++ rsb_util.c
@@ -161,6 +161,26 @@ void rsb__util_set_area_to_converted_int
 	return;
 }
 
+/*
+ *  Added because of lack of functionality with FreeBSD
+ *  See https://wiki.freebsd.org/Numerics
+ */
+complex float clogf(complex float a) {
+	return logf(cabsf(a)) + I*cargf(a);
+}
+
+complex float cpowf(complex float a, complex float b) {
+	return cexpf(b*clogf(a));
+}
+
+complex double clog(complex double a) {
+	return logf(cabs(a)) + I*carg(a);
+}
+
+complex double cpow(complex double a, complex double b) {
+	return cexp(b*clog(a));
+}
+
 rsb_coo_idx_t * rsb__util_get_partitioning_array( size_t bs, size_t X , rsb_blk_idx_t * X_b, rsb_flags_t flags){
 	/*!
 	 * Given a block size (be it rows or columns), an element size X in bytes,
