--- module/icp/algs/blake3/blake3_x86-64.c.orig	2022-09-06 07:44:01 UTC
+++ module/icp/algs/blake3/blake3_x86-64.c
@@ -74,7 +74,7 @@ static boolean_t blake3_is_sse2_supported(void)
 {
 #if defined(__x86_64)
 	return (kfpu_allowed() && zfs_sse2_available());
-#elif defined(__PPC64__)
+#elif defined(__PPC64__) && defined(__linux__)
 	return (kfpu_allowed() && zfs_vsx_available());
 #else
 	return (kfpu_allowed());
@@ -140,7 +140,7 @@ static boolean_t blake3_is_sse41_supported(void)
 {
 #if defined(__x86_64)
 	return (kfpu_allowed() && zfs_sse4_1_available());
-#elif defined(__PPC64__)
+#elif defined(__PPC64__) && defined(__linux__)
 	return (kfpu_allowed() && zfs_vsx_available());
 #else
 	return (kfpu_allowed());
