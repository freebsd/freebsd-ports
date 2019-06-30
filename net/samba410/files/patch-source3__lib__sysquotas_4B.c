--- source3/lib/sysquotas_4B.c.orig	2019-01-28 03:56:23 UTC
+++ source3/lib/sysquotas_4B.c
@@ -141,7 +141,14 @@ static int sys_quotactl_4B(const char * 
 		/* ENOTSUP means quota support is not compiled in. EINVAL
 		 * means that quotas are not configured (commonly).
 		 */
-		if (errno != ENOTSUP && errno != EINVAL) {
+		if (errno != ENOTSUP && errno != EINVAL
+/*
+ * FreeBSD 12 between r336017 and r342928 wrongfuly return ENOENT for the not enabled qoutas on ZFS.
+ */
+#if defined(__FreeBSD__) && ((__FreeBSD_version >= 1102503 && __FreeBSD_version <= 1102506) || (__FreeBSD_version >= 1200072 && __FreeBSD_version <= 1200503) || (__FreeBSD_version >= 1300000 && __FreeBSD_version <= 1300009))
+			&& errno != ENOENT
+#endif
+		) {
 			DEBUG(0, ("failed to %s quota for %s ID %u on %s: %s\n",
 				    (cmd & QCMD(Q_GETQUOTA, 0)) ? "get" : "set",
 				    (cmd & QCMD(0, GRPQUOTA)) ? "group" : "user",
