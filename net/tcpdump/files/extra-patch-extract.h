--- extract.h.orig	Wed Dec 11 07:13:51 2002
+++ extract.h	Wed Dec 10 18:45:34 2003
@@ -96,3 +96,12 @@
 		     (u_int32_t)*((const u_int8_t *)(p) + 2) << 16 | \
 		     (u_int32_t)*((const u_int8_t *)(p) + 1) << 8 | \
 		     (u_int32_t)*((const u_int8_t *)(p) + 0)))
+#define EXTRACT_LE_64BITS(p) \
+	((u_int64_t)((u_int64_t)*((const u_int8_t *)(p) + 7) << 56 | \
+		     (u_int64_t)*((const u_int8_t *)(p) + 6) << 48 | \
+		     (u_int64_t)*((const u_int8_t *)(p) + 5) << 40 | \
+		     (u_int64_t)*((const u_int8_t *)(p) + 4) << 32 | \
+	             (u_int64_t)*((const u_int8_t *)(p) + 3) << 24 | \
+		     (u_int64_t)*((const u_int8_t *)(p) + 2) << 16 | \
+		     (u_int64_t)*((const u_int8_t *)(p) + 1) << 8 | \
+		     (u_int64_t)*((const u_int8_t *)(p) + 0)))
