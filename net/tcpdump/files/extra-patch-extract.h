--- extract.h.orig	Tue Dec 10 23:13:51 2002
+++ extract.h	Tue Mar 30 20:38:35 2004
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
