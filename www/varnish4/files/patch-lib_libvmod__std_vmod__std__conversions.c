--- lib/libvmod_std/vmod_std_conversions.c.orig	2019-02-11 14:06:27 UTC
+++ lib/libvmod_std/vmod_std_conversions.c
@@ -45,6 +45,21 @@
 #include "vtim.h"
 #include "vcc_if.h"
 
+/*
+ * technically, as our VCL_INT is int64_t, its limits are INT64_MIN/INT64_MAX.
+ *
+ * Yet, for conversions, we use VNUMpfx with a double intermediate, so above
+ * 2^53 we see rounding errors. In order to catch a potential floor rounding
+ * error, we make our limit 2^53-1
+ *
+ * Ref: https://stackoverflow.com/a/1848762
+ */
+#define VCL_INT_MAX ((INT64_C(1)<<53)-1)
+#define VCL_INT_MIN (-VCL_INT_MAX)
+
+#define VCL_BYTES_MAX VCL_INT_MAX
+#define VCL_BYTES_MIN 0
+
 VCL_DURATION __match_proto__(td_std_duration)
 vmod_duration(VRT_CTX, VCL_STRING p, VCL_DURATION d)
 {
@@ -195,7 +210,7 @@ vmod_real2integer(VRT_CTX, VCL_REAL r, VCL_INT i)
 	if (!isfinite(r))
 		return (i);
 	r = round(r);
-	if (r > LONG_MAX || r < LONG_MIN)
+	if (r > VCL_INT_MAX || r < VCL_INT_MIN)
 		return(i);
 	return ((long)r);
 }
@@ -219,7 +234,7 @@ vmod_time2integer(VRT_CTX, VCL_TIME t, VCL_INT i)
 	if (!isfinite(t))
 		return (i);
 	t = round(t);
-	if (t > LONG_MAX || t < LONG_MIN)
+	if (t > VCL_INT_MAX || t < VCL_INT_MIN)
 		return(i);
 	return ((long)t);
 }
